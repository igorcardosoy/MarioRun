#include "../include/sky.h"

struct sky_type {
  int x, y;
  int width, height;
  SDL_Texture* texture;
};

void sky_init(Sky* sky, SDL_Renderer* renderer)
{
  *sky = malloc(sizeof(struct sky_type));
  if (*sky != NULL) {
    (*sky)->x = 0;
    (*sky)->y = 0;
    (*sky)->texture = IMG_LoadTexture(renderer, "src/assets/images/clouds_pixelart.png");

    if ((*sky)->texture == NULL) {
      printf("%s\n", SDL_GetError());
    }

  } else {
    printf("Erro ao alocar céu!\n");
  }
}

void sky_animate(Sky sky, SDL_Renderer* renderer, int width, int height, double speed)
{
  sky->height = height;
  sky->width = width;

  sky->x -= (speed / 2);
  if (sky->x < -sky->width) {
    sky->x = 0;
  }

  SDL_Rect rect = { sky->x, sky->y, sky->width * 2, sky->height };
  SDL_RenderCopy(renderer, sky->texture, NULL, &rect);
}

void sky_destroy(Sky* sky)
{
  SDL_DestroyTexture((*sky)->texture);
  free(*sky);
}