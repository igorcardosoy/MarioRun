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
  bool is_falling;
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
    (*character)->bottom = height * 0.705;
    (*character)->y = (*character)->bottom;
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
        printf("%s\n", SDL_GetError());
      }
    }
  } else {
    printf("Erro ao alocar personagem!\n");
  }
}

void character_animate(Character character, SDL_Renderer* renderer, int width, int height, int speed)
{
  character->width = (width * 0.08);
  character->height = (height * 0.15);
  character->bottom = height * 0.705;

  if (character->is_dead) {
    character->gravity = 0.01;
  } else {
    character->gravity = 0.03;
  }

  // Gravidade 
  if (character->y < character->bottom || character->is_dead) {
    character->speed += character->gravity;
    character->y += character->speed;
  }

  if (character->y == character->bottom && !character->is_dead) {
    character->speed = 0;
  }

  if (character->y >= character->bottom && !character->is_dead)
    character->y = character->bottom;

  // Reset da animação.
  if (!(character->y < character->bottom)) {

    character->frame += (speed * 0.02);

    if (character->frame >= 12) {
      character->frame = 0;
    }
  } else {
    if (character->is_falling)
      character->frame = 3;
    else
      character->frame = 1;
  }

  SDL_Texture* texture = character->animation[(int)character->frame];
  int render_height = character->height;
  int render_width = character->width;
  int render_y = character->y;
  int render_x = character->x;

  if (character->is_dead) {
    texture = character->texture_dead;
    render_width *= 0.65;
  } else if (character->is_crouched) {
    texture = character->texture_crouched;
    render_height *= 0.60;
    render_width *= 0.65;
    render_y *= 1.085;
    render_x *= 1.25;
  }

  SDL_Rect characterRect = { render_x, render_y, render_width, render_height };
  SDL_RenderCopy(renderer, texture, NULL, &characterRect);

}

bool character_can_jump(Character character)
{
  return character->y == character->bottom;
}

void character_set_falling(Character character, bool is_falling)
{
  character->is_falling = is_falling;
}

void character_jump_sound(Character character)
{
  Mix_PlayChannel(-1, character->jump_sound, 0);
}

void character_jump(Character character)
{
  character->y -= 5;
}

void character_fall(Character character, int height)
{
  character->y += height * 0.008;
}

void character_crouch(Character character, bool is_crouched)
{
  if (is_crouched) {
    character->is_crouched = true;
  } else {
    character->is_crouched = false;
  }
}

bool character_is_crouched(Character character)
{
  return character->is_crouched;
}

void character_set_dead(Character character, bool is_dead)
{
  if (is_dead) {
    Mix_PlayChannel(-1, character->death_sound, 0);
    character->is_dead = true;
  } else {
    character->is_dead = false;
  }
}

bool character_is_dead(Character character)
{
  return character->is_dead;
}

bool character_is_ondisplay(Character character, int height)
{
  return character->y < character->height + height;
}

void character_get_colision(Character character, int* x1, int* x2, int* y1, int* y2)
{
  int render_height = character->is_crouched ? character->height * 0.60 : character->height;
  int render_width = character->is_crouched ? character->width * 0.65 : character->width;
  int render_y = character->is_crouched ? character->y * 1.085 : character->y;
  int render_x = character->is_crouched ? character->x * 1.25 : character->x;

  if (!character->is_crouched) {
    *x1 = render_x + render_width * 0.6;
    *x2 = render_x + render_width;
    *y1 = render_y;
    *y2 = render_y + render_height;
  } else {
    *x1 = render_x;
    *x2 = render_x + render_width;
    *y1 = render_y;
    *y2 = render_y + render_height;
  }
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

  SDL_DestroyTexture((*character)->texture_crouched);
  SDL_DestroyTexture((*character)->texture_dead);
  Mix_FreeChunk((*character)->death_sound);
  Mix_FreeChunk((*character)->jump_sound);
  free(*character);
}