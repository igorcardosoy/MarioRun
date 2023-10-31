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
    (*obstacle)->x = //not implemented;
    (*obstacle)->y = //not implemented;
    (*obstacle)->width = width;
    (*obstacle)->height = height;

    char path[50];
    sprintf(path, "assets/images/obstacle%d.png", type);
    (*obstacle)->texture = IMG_LoadTexture(renderer, path);
  } else {
    printf("Erro ao alocar memoria para o obstaculo!\n");
  }
}

void obstacle_animate(Obstacle obstacle, SDL_Renderer* renderer, int width, int height, double speed)
{
  //not implemented
}

int obstacle_get_position_x(Obstacle obstacle)
{
  //not implemented
}

void obstacle_set_position_x(Obstacle obstacle, int x)
{
  //not implemented
}

int obstacle_get_width(Obstacle obstacle)
{
  //not implemented
}

void obstacle_get_colision(Obstacle obstacle, double* x1, double* x2, double* y1, double* y2)
{
  //not implemented
}

void obstacle_destroy(Obstacle* obstacle)
{
  //not implemented
}