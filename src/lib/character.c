#include "../include/character.h"

struct character_type {
  int x, y;
  int width, height;
  int bottom;
  double gravity;
  double speed;
  double frame;
  bool is_dead;
  bool is_crouched;
  SDL_Texture* animation[12];
  SDL_Texture* texture_crouched;
  SDL_Texture* texture_dead;
  Mix_Chunk* death_sound;
  Mix_Chunk* jump_sound;
};

void character_init(Character* character, SDL_Renderer* renderer, int width, int height)
{

  *character = malloc(sizeof(struct character_type));

  if (*character != NULL) {

    (*character)->death_sound = Mix_LoadWAV("./src/assets/audios/mario_morreu.mp3");
    (*character)->jump_sound = Mix_LoadWAV("./src/assets/audios/mario_pulo_alto.mp3");

    (*character)->x = width * 0.1;
    (*character)->y = 0;
    (*character)->width = width * 0.15;
    (*character)->height = height * 0.15;
    (*character)->speed = 0;
    (*character)->gravity = 0.03;
    (*character)->frame = 0;
    (*character)->is_dead = false;
    (*character)->is_crouched = false;
    (*character)->texture_dead = IMG_LoadTexture(renderer, "./src/assets/images/mario_dead.png");
    (*character)->texture_crouched = IMG_LoadTexture(renderer, "./src/assets/images/mario_crouched.png");

    for (int i = 0; i < 12; i++) {
      char path[50];
      snprintf(path, 50, "src/assets/images/Mario/mario_frame%d.png", i);
      (*character)->animation[i] = IMG_LoadTexture(renderer, path);

      if ((*character)->animation[i] == NULL) {
        printf("Erro ao carregar textura do personagem!\n");
      }
    }
  }
}

void character_animate(Character character, SDL_Renderer* renderer, int width, int height, int speed)
{
  character->width = (width * 0.15);
  character->height = (height * 0.15);
  character->bottom = height * 0.705;

  // Gravidade 
  if (character->y < character->bottom) {
    character->speed += character->gravity;
    character->y += character->speed;
  }

  if (character->y == character->bottom) {
      character->speed = 0;
    }

  if (character->y >= character->bottom)
    character->y = character->bottom;

  // Reset da animação.
  if (!(character->y < character->bottom)) {
    if (character->frame >= 12){
      character->frame = 0;
    } else {
      character->frame += (speed * 0.02);
    }
  }

  SDL_Texture* texture = character->is_crouched ? character->texture_crouched : character->animation[(int) character->frame];

  SDL_Rect characterRect = { character->x, (character->is_crouched ? character->y * 1.11 : character->y), character->height, (character->is_crouched ? character->height * 0.5 : character->height)};
  SDL_RenderCopy(renderer, texture, NULL, &characterRect);

}

bool character_can_jump(Character character)
{
  return character->y == character->bottom;
}

void character_jump_sound(Character character)
{
  Mix_PlayChannel(-1, character->jump_sound, 0);
}

void character_jump(Character character)
{
    character->y -= 10;
}

void character_fall(Character character, int height)
{
    character->y += height * 0.01;
}

void character_crouch(Character character, SDL_Renderer* renderer, bool is_crouched)
{
  if (is_crouched)
  {
    character->is_crouched = true;
  } else {
    character->is_crouched = false;
  }
}

void character_set_dead(Character character, bool is_dead)
{
  if (is_dead)
  {
    Mix_PlayChannel(-1, character->death_sound, 0);
    character->is_dead = true;
  } else {
    character->is_dead = false;
  }
}

void character_get_colision(Character character, double* x1, double* x2, double* y1, double* y2)
{
  *x1 = character->x + character->width / 2;
  *x2 = character->x - character->width / 2;
  *y1 = character->y + character->height / 2;
  *y2 = character->y - character->height / 2;
}

int character_get_position_y(Character character)
{
  return character->y;
}

void character_destroy(Character* character)
{
  for (int i = 0; i < 12; i++) {
    SDL_DestroyTexture((*character)->animation[i]);
  }

  free(*character);

}