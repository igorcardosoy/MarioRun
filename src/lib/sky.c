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
    (*sky)->x = 0;
    (*sky)->y = 0;
    (*sky)->width = width;
    (*sky)->height = height;
    (*sky)->texture = IMG_LoadTexture(renderer, "src/assets/images/clouds_pixelart.png");
  }
}

void sky_animate(Sky sky, SDL_Renderer* renderer, int width, int height, double speed)
{
  sky->height = height;
  sky->width = width;

  sky->x -= (speed / 2);
  if (sky->x < -sky->width) {
    sky->x = sky->width * 0.018;
  }

  SDL_SetRenderDrawColor(renderer, 94, 145, 254, 255);

  SDL_Rect rect = { sky->x, sky->y-(height*0.5)+(height * 0.15), sky->width * 2, sky->height};
  SDL_RenderCopy(renderer, sky->texture, NULL, &rect);
}

void sky_destroy(Sky* sky)
{
  SDL_DestroyTexture((*sky)->texture);
  free(*sky);
}