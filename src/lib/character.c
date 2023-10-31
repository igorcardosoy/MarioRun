#include "../include/character.h"

struct character_type {
  int x, y;
  int width, height;
  int gravity;
  bool is_dead;
  SDL_Texture* texture; // Por enquanto a textura indica uma imagem estatica, mas depois pode ser um vetor de texturas para animacao ou um gif.
  SDL_Texture* texture_dead;
};

void character_init(Character* character, SDL_Renderer* renderer, int width, int height)
{
  //not implemented
}

void character_animate(Character character, SDL_Renderer* renderer, SDL_Window* window)
{
  //not implemented
}

void character_jump(Character character, int height)
{
  //not implemented
}

void character_fall(Character character, int height)
{
  //not implemented
}

void character_get_colision(Character character, double* x1, double* x2, double* y1, double* y2)
{
  //not implemented
}

int character_get_position_y(Character character)
{
  //not implemented
}

void character_destroy(Character character)
{
  //not implemented
}