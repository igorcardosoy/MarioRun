#include "../include/mario_run.h"

struct game_type {
  Sky sky;
  Ground ground;
  Character character;
  Obstacle obstacle;
  Queue queue;
  Text text;
  double speed;
  double score;

  Mix_Music* main_song;

  SDL_Renderer* renderer;
  SDL_Window* window;

  int width, height;
  int int_score;
};

void game_init(Game* game)
{
  *game = malloc(sizeof(struct game_type));

  if (*game != NULL) {

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    Mix_Init(MIX_INIT_MP3);
    TTF_Init();

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

    (*game)->speed = 4;
    (*game)->score = 0;
    (*game)->int_score = 50;

    (*game)->window = SDL_CreateWindow("Mario Run", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 760, 540, SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);
    (*game)->renderer = SDL_CreateRenderer((*game)->window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawBlendMode((*game)->renderer, SDL_BLENDMODE_BLEND);

    SDL_GetWindowSize((*game)->window, &(*game)->width, &(*game)->height);

    (*game)->main_song = Mix_LoadMUS("./src/assets/audios/musica_tema.mp3");

    sky_init(&(*game)->sky, (*game)->renderer);
    ground_init(&(*game)->ground, (*game)->renderer);
    character_init(&(*game)->character, (*game)->renderer, (*game)->width, (*game)->height);
    text_init(&(*game)->text);

    queue_init(&(*game)->queue);
    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
      int type = (rand() % 5) + 1;

      obstacle_init(&(*game)->obstacle, (*game)->renderer, (*game)->width, (*game)->height, type);
      queue_enqueue((*game)->queue, (*game)->obstacle);
    }

  } else {
    printf("Erro ao alocar jogo!\n");
  }
}

bool game_menu(Game game, bool is_dead)
{
  bool quit, stop;
  quit = stop = false;
  SDL_Event event;
  SDL_Rect rect = { 0, 0, game->width, game->height };

  game->speed = 0;
  game_animate(game, false);

  if (!is_dead) {

    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 200);
    SDL_RenderFillRect(game->renderer, &rect);
    SDL_RenderPresent(game->renderer);

    text_render(game->text, game->renderer, game->width * 0.35, game->height * 0.1, game->width * 3, game->height, "src/assets/fonts/font.ttf", 100, "Mario Run");
    text_render(game->text, game->renderer, game->width * 0.3, game->height * 0.5, game->width * 4, game->height / 2, "src/assets/fonts/font.ttf", 100, "Pressione qualquer tecla para jogar");
    text_render(game->text, game->renderer, 10, 0, game->width * 2, game->height / 3, "src/assets/fonts/font.ttf", 50, "Pressione ESC para sair");
  } else {

    for (int i = 0; i < 200; i += 3) {
      game_animate(game, false);
      SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, i);
      SDL_RenderFillRect(game->renderer, &rect);
      SDL_RenderPresent(game->renderer);

      SDL_Delay(10);
    }

    text_render(game->text, game->renderer, game->width * 0.35, game->height * 0.1, game->width * 3, game->height, "src/assets/fonts/font.ttf", 100, "Game Over");
    text_render(game->text, game->renderer, game->width * 0.25, game->height * 0.5, game->width * 5, game->height / 2, "src/assets/fonts/font.ttf", 100, "Pressione a tecla ENTER para jogar novamente");
    text_render(game->text, game->renderer, 10, 0, game->width * 2, game->height / 3, "src/assets/fonts/font.ttf", 50, "Pressione ESC para sair");
  }

  SDL_RenderPresent(game->renderer);

  while (!stop) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          quit = true;
          stop = true;
          break;
        case SDL_KEYDOWN:
          switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
              quit = true;
              stop = true;
              break;
            case SDLK_RETURN:
              stop = true;
              break;
            default:
              if (!is_dead) {
                stop = true;
              }

              break;
          }
      }
    }
  }

  if (!quit) {
    for (int i = 200; i > 0; i -= 5) {
      game_animate(game, false);
      SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, i);
      SDL_RenderFillRect(game->renderer, &rect);
      SDL_RenderPresent(game->renderer);

      SDL_Delay(10);
    }
  }

  game->speed = 4;

  return quit;
}

void game_animate(Game game, bool render)
{
  double speed = character_is_dead(game->character) ? 0 : game->speed;

  if (character_can_jump(game->character))
    character_set_falling(game->character, false);

  SDL_RenderClear(game->renderer);

  if (!character_is_dead(game->character)) {
    game->score += 0.01 * game->speed;
    if (game->score > game->int_score && game->score < 800) {
      game->int_score += 50;
      game->speed += 1;
    }
  }

  sky_animate(game->sky, game->renderer, game->width, game->height, speed);
  obstacle_animate(game->obstacle, game->renderer, game->width, game->height, speed);
  ground_animate(game->ground, game->renderer, game->width, game->height, speed);

  if (obstacle_get_position_x(game->obstacle) <= -obstacle_get_width(game->obstacle)) {
    int type = (rand() % 5) + 1;

    obstacle_destroy(&game->obstacle);
    game->obstacle = NULL;

    obstacle_init(&(game->obstacle), game->renderer, game->width, game->height, type);
    queue_enqueue(game->queue, game->obstacle);
    game->obstacle = queue_dequeue(game->queue);

    // Por algumo motivo quando o primeiro elemento que é dado o enqueue fica invisivel quando as posições são resetadas, o resto funciona normalmente.
    // obstacle_reset_position(game->obstacle, game->width, game->height);
  }

  character_animate(game->character, game->renderer, game->width, game->height, speed);

  char score[10];
  snprintf(score, 10, "%d", (int)game->score);

  if (game->score > 100) {
    text_render(game->text, game->renderer, game->width * 0.87, 0, game->width, game->height, "src/assets/fonts/font.ttf", 50, score);
  } else if (game->score > 10) {
    text_render(game->text, game->renderer, game->width * 0.90, 0, game->width * 0.75, game->height, "src/assets/fonts/font.ttf", 50, score);
  } else {
    text_render(game->text, game->renderer, game->width * 0.93, 0, game->width * 0.50, game->height, "src/assets/fonts/font.ttf", 50, score);
  }

  if (render)
    SDL_RenderPresent(game->renderer);

}

bool game_events(Game game)
{
  bool stop = false;
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_WINDOWEVENT:
        if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
          SDL_GetWindowSize(game->window, &game->width, &game->height);
          obstacle_reset_position(game->obstacle, game->width, game->height);
        }
        break;
      case SDL_QUIT:
        SDL_DestroyWindow(game->window);
        stop = true;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
          case SDLK_ESCAPE:
            stop = true;
            break;
          case SDLK_UP:
          case SDLK_SPACE:
            if (character_can_jump(game->character) && !character_is_crouched(game->character)) {
              character_jump_sound(game->character);
              int jump_size = game->height * 0.06;

              character_jump(game->character);
              game_frame(game, &stop);

              for (int i = 0; i < jump_size && !character_can_jump(game->character); i++) {
                character_jump(game->character);
                game_frame(game, &stop);
              }

              const Uint8* state = SDL_GetKeyboardState(NULL);
              if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_SPACE]) {
                for (int i = 0; i < jump_size * 0.5 && !character_can_jump(game->character); i++) {
                  character_jump(game->character);
                  game_frame(game, &stop);
                }
              }

              character_set_falling(game->character, true);
            }
            break;
          case SDLK_DOWN:
            if (!character_is_dead(game->character)) {
              const Uint8* state = SDL_GetKeyboardState(NULL);
              if (state[SDL_SCANCODE_DOWN]) {
                character_set_falling(game->character, true);
                if (!character_can_jump(game->character)) {
                  for (int i = 0; i < game->height * 0.13 && !character_can_jump(game->character); i++) {
                    character_fall(game->character, game->height);
                    game_frame(game, &stop);
                  }
                } else {
                  while (state[SDL_SCANCODE_DOWN]) {
                    character_crouch(game->character, true);
                    game_frame(game, &stop);
                  }
                }
                character_crouch(game->character, false);
              }
            }


        }
    }
  }
  return stop;
}

void game_pause(Game game)
{
  game_animate(game, true);

  while (true) {
    game_events(game);
  }
}

void game_run(Game game)
{
  bool quit = false;

  if (!game_menu(game, false)) {

    Mix_PlayMusic(game->main_song, -1);
    Mix_VolumeMusic(MIX_MAX_VOLUME / 2);

    while (!quit) {
      game_frame(game, &quit);
    }
  }

  game_destroy(&game);
}

void game_frame(Game game, bool* quit)
{
  int frame_time;
  int startLoop;

  startLoop = SDL_GetTicks();

  game_animate(game, true);

  *quit = game_events(game);

  if (are_colliding(game->character, game->obstacle) && !*quit) {
    SDL_Delay(1000);
    character_set_dead(game->character, true);

    game->speed = 0;

    while (character_is_ondisplay(game->character, game->height)) {
      game_animate(game, true);
    }

    *quit = game_menu(game, true);

    if (!*quit)
      game_reset(game);
  }

  frame_time = SDL_GetTicks() - startLoop;
  if (frame_time < FRAME_TIME) {
    SDL_Delay(FRAME_TIME - frame_time);
  }

  *quit = character_is_dead(game->character);
}

void game_reset(Game game)
{
  character_destroy(&game->character);

  obstacle_reset_position(game->obstacle, game->width, game->height);
  
  game->score = 0;
  game->int_score = 50;
  game->speed = 4;

  character_init(&game->character, game->renderer, game->width, game->height);
}

bool are_colliding(Character character, Obstacle obstacle)
{
  int c_left, c_right, c_top, c_bottom;
  int o_left, o_right, o_top, o_bottom;

  character_get_colision(character, &c_left, &c_right, &c_top, &c_bottom);
  obstacle_get_colision(obstacle, &o_left, &o_right, &o_top, &o_bottom);

  if (c_bottom <= o_top)
    return false;
  if (c_top >= o_bottom)
    return false;
  if (c_right <= o_left)
    return false;
  if (c_left >= o_right)
    return false;

  return true;
}

void game_destroy(Game* game)
{
  sky_destroy(&(*game)->sky);
  ground_destroy(&(*game)->ground);
  character_destroy(&(*game)->character);
  obstacle_destroy(&(*game)->obstacle);
  queue_destroy(&(*game)->queue);

  Mix_CloseAudio();
  Mix_FreeMusic((*game)->main_song);

  SDL_DestroyWindow((*game)->window);
  SDL_DestroyRenderer((*game)->renderer);

  free(*game);

  Mix_Quit();
  IMG_Quit();
  TTF_Quit();
  TTF_Quit();
  SDL_Quit();
}