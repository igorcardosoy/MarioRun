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
};

void game_init(Game* game)
{

  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_PNG);
  Mix_Init(MIX_INIT_MP3);
  TTF_Init();

  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
  // (*game)->main_song = Mix_LoadMUS("./src/assets/audios/music.mp3");

  *game = malloc(sizeof(struct game_type));
  if (*game != NULL) {
    (*game)->speed = 1;
    (*game)->score = 0;

    (*game)->window = SDL_CreateWindow("Mario Run", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 760, 540, SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);
    (*game)->renderer = SDL_CreateRenderer((*game)->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_GetWindowSize((*game)->window, &(*game)->width, &(*game)->height);

    sky_init(&(*game)->sky, (*game)->renderer, (*game)->width, (*game)->height);
    ground_init(&(*game)->ground, (*game)->renderer, (*game)->width, (*game)->height);
    character_init(&(*game)->character, (*game)->renderer, (*game)->width, (*game)->height);
    text_init(&(*game)->text);

    // queue_init(&(*game)->queue);
    // srand(time(NULL));

    // for (int i = 0; i < 9; i++) {
    //   int type = (rand() % 10) + 1;

    //   obstacle_init(&(*game)->obstacle, (*game)->renderer, (*game)->width, (*game)->height, type);
    //   queue_enqueue((*game)->queue, (*game)->obstacle);
    // }

  }
}

bool game_menu(Game game, bool is_dead)
{
  //not implemented
}

void game_animate(Game game)
{

  SDL_GL_GetDrawableSize(game->window, &game->width, &game->height);

  SDL_RenderClear(game->renderer);

  sky_animate(game->sky, game->renderer, game->width, game->height, game->speed);
  ground_animate(game->ground, game->renderer, game->width, game->height, game->speed);
  character_animate(game->character, game->renderer, game->width, game->height);

  // obstacle_animate(game->obstacle, game->renderer, game->width, game->height, game->speed);
  // if (obstacle_get_position_x(game->obstacle) == -obstacle_get_width(game->obstacle)) {
  //   obstacle_set_position_x(game->obstacle, game->width + obstacle_get_width(game->obstacle));

  //   int type = (rand() % 10) + 1;
  //   obstacle_init(&game->obstacle, game->renderer, game->width, game->height, type);
  //   queue_enqueue(game->queue, game->obstacle);

  //   game->obstacle = queue_dequeue(game->queue);
  // }

  game->score += 0.01 * game->speed;

  if ((int)game->score % 100 == 0 && game->score < 1500) {
    game->speed += 0.20;
  }

  char score[10];
  snprintf(score, 10, "%d", (int)game->score);
  text_render(game->text, game->renderer, 0, 0, game->width, game->height, "src/assets/fonts/font.ttf", 50, score);

  SDL_RenderPresent(game->renderer);
}

bool game_events(Game game)
{
  bool stop = false;
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_WINDOWEVENT_CLOSE:
        if (game->window) {
          SDL_DestroyWindow(game->window);
          game->window = NULL;
          stop = true;
        }
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
          case SDLK_ESCAPE:
            stop = true;
            break;
          case SDLK_UP:
          case SDLK_SPACE:
            character_jump(game->character, game->height);
            stop = true;
            break;
          case SDLK_DOWN:
            character_fall(game->character, game->height);
            stop = true;
            break;
          case SDL_QUIT:
            stop = true;
            break;
        }
    }
  }

  return stop;
}

void game_run(Game game, bool* quit)
{

  // Mix_PlayMusic(game->main_song, -1);

  game_menu(game, false);

  while (!*quit) {
    game_animate(game);
    *quit = game_events(game);

    // if (are_colliding(game->character, game->obstacle) && !*quit) {
    //   character_set_dead(game->character, true);
    //   *quit = game_menu(game, true);
    //   game_reset(game);
    // }
  }

  game_destroy(&game);
}

void game_reset(Game game)
{
  // Não sei se essa implementação funciona, deixar provisioriamente até futuros testes.
  game_destroy(&game);
  game_init(&game);
}

bool are_colliding(Character character, Obstacle obstacle)
{
  double c_x1, c_x2, c_y1, c_y2;
  double o_x1, o_x2, o_y1, o_y2;

  character_get_colision(character, &c_x1, &c_x2, &c_y1, &c_y2);
  obstacle_get_colision(obstacle, &o_x1, &o_x2, &o_y1, &o_y2);

  if (c_x1 < o_x2)
    return false;
  if (c_x2 > o_x1)
    return false;
  if (c_y1 < o_y2)
    return false;
  if (c_y2 > o_y1)
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
  text_destroy(&(*game)->text);
  SDL_DestroyWindow((*game)->window);
  SDL_DestroyRenderer((*game)->renderer);

  free(*game);
  SDL_Quit();
}