#include "../include/ground.h"


struct ground_type {
  int x, y;
  int width, height;
  SDL_Texture* texture;
};

void ground_init(Ground* ground, SDL_Renderer* renderer, int width, int height)
{
  *ground = malloc(sizeof(struct ground_type));
  if (*ground != NULL) {
    (*ground)->x = 0;
    (*ground)->y = 0;
    (*ground)->width = width;
    (*ground)->height = height;
    (*ground)->texture = IMG_LoadTexture(renderer, "src/assets/images/mario_cenary.png");
  }
}

void ground_animate(Ground ground, SDL_Renderer* renderer, int width, int height, double speed)
{
  ground->height = height;
  ground->width = width;

  ground->x -= speed;
  if (ground->x <= -width-speed) {
    ground->x = 0;
  }

  SDL_Rect rect = { ground->x, ground->y, ground->width * 2, ground->height };
  SDL_RenderCopy(renderer, ground->texture, NULL, &rect);
}

void ground_destroy(Ground* ground)
{
  SDL_DestroyTexture((*ground)->texture);
  free(*ground);
}