#include "../include/sky.h"

struct sky_type {
  int x, y;
  int width, height;
  SDL_Texture* texture;
};

void sky_init(Sky* sky, SDL_Renderer* renderer, int width, int height)
{
  *sky = malloc(sizeof(struct sky_type));
  if (*sky != NULL) {
    (*sky)->x = //not implemented;
    (*sky)->y = //not implemented;
    (*sky)->width = width;
    (*sky)->height = height;
    (*sky)->texture = IMG_LoadTexture(renderer, "src/assets/sky.png");
  }
}

void sky_animate(Sky sky, SDL_Renderer* renderer, int width, int height, double speed)
{
  sky->height = height;
  sky->width = width;

  sky->x -= speed;
  if (sky->x <= -width) {
    sky->x = width;
  }

  SDL_SetRenderDrawColor(renderer, 94, 145, 254, 255);

  SDL_Rect rect = { sky->x, sky->y, sky->width * 2, sky->height };
  SDL_RenderCopy(renderer, sky->texture, NULL, &rect);
}

void sky_destroy(Sky* sky)
{
  SDL_DestroyTexture((*sky)->texture);
  free(*sky);
}