#include "../include/obstacle.h"

struct obstacle_type {
  int x, y;
  int width, height;
  SDL_Texture* texture;
};

void obstacle_init(Obstacle* obstacle, SDL_Renderer* renderer, int width, int height, int type)
{
  *obstacle = malloc(sizeof(struct obstacle_type));

  if (*obstacle != NULL) {

    printf("%d\n", type);

    (*obstacle)->x = width;
    (*obstacle)->y = height * 0.853;

    switch (type) {
      case 1:
        (*obstacle)->width = width * 0.15;
        (*obstacle)->height = height * 0.15;
        break;
      case 2:
        (*obstacle)->width = width * 0.15;
        (*obstacle)->height = height * 0.15;
        break;
      case 3:
        (*obstacle)->width = width * 0.15;
        (*obstacle)->height = height * 0.15;
        break;
      default:
        break;
    }

    char path[40];
    snprintf(path, 40, "./src/assets/images/pipes/pipe%d.png", type);
    (*obstacle)->texture = IMG_LoadTexture(renderer, path);

    if ((*obstacle)->texture == NULL) {
      printf("%s\n", SDL_GetError());
    }

  } else {
    printf("Erro ao alocar obstaculo!\n");
  }
}

void obstacle_animate(Obstacle obstacle, SDL_Renderer* renderer, int width, int height, double speed)
{

  obstacle->width = width * 0.15;
  obstacle->height = height * 0.15;
  obstacle->y = height * 0.853;

  obstacle->x -= speed;
  SDL_Rect rect = { obstacle->x, obstacle->y - obstacle->height, obstacle->width, obstacle->height };
  SDL_RenderCopy(renderer, obstacle->texture, NULL, &rect);
}

int obstacle_get_position_x(Obstacle obstacle)
{
  return obstacle->x;
}

void obstacle_set_position_x(Obstacle obstacle, int x)
{
  obstacle->x = x;
}

int obstacle_get_width(Obstacle obstacle)
{
  return obstacle->width;
}

void obstacle_get_colision(Obstacle obstacle, double* x1, double* x2, double* y1, double* y2)
{
  *x1 = obstacle->x + obstacle->width / 2;
  *x2 = obstacle->x - obstacle->width / 2;
  *y1 = obstacle->y + obstacle->height / 2;
  *y2 = obstacle->y - obstacle->height / 2;
}

void obstacle_destroy(Obstacle* obstacle)
{
  SDL_DestroyTexture((*obstacle)->texture);
  free(*obstacle);
}