#include "../include/obstacle.h"

struct obstacle_type {
  int x, y;
  int width, height;
  int type;
  SDL_Texture* texture;
};

void obstacle_init(Obstacle* obstacle, SDL_Renderer* renderer, int width, int height, int type)
{
  *obstacle = malloc(sizeof(struct obstacle_type));

  if (*obstacle != NULL) {

    (*obstacle)->x = width;
    (*obstacle)->y = height * 0.704;
    (*obstacle)->type = type;

    char path[45];
    snprintf(path, 45, "./src/assets/images/obstacles/obstacle%d.png", (*obstacle)->type == 5 ? 4 : (*obstacle)->type); 
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
  switch (obstacle->type) {
    case 1:
      obstacle->width = width * 0.08;
      obstacle->height = height * 0.15;
      break;
    case 2:
      obstacle->width = width * 0.13;
      obstacle->height = height * 0.15;
      break;
    case 3:
      obstacle->width = width * 0.18;
      obstacle->height = height * 0.15;
      break;
    case 4:
      obstacle->width = width * 0.09;
      obstacle->height = height * 0.11;
      if (obstacle->x == width) {
        obstacle->y = height * 0.65;
      }
      break;
    case 5:
      obstacle->width = width * 0.09;
      obstacle->height = height * 0.11;
      if (obstacle->x == width) {
        obstacle->y = height * 0.5;
      }
      break;
  }

  obstacle->x -= speed;

  SDL_Rect rect = { obstacle->x, obstacle->y, obstacle->width, obstacle->height };
  SDL_RenderCopy(renderer, obstacle->texture, NULL, &rect);

}

int obstacle_get_position_x(Obstacle obstacle)
{
  return obstacle->x;
}

void obstacle_reset_position(Obstacle obstacle, int width, int height)
{
  obstacle->x = width;
  obstacle->y = height * 0.704;
}


int obstacle_get_width(Obstacle obstacle)
{
  return obstacle->width;
}

void obstacle_get_colision(Obstacle obstacle, int* x1, int* x2, int* y1, int* y2)
{
  if (obstacle->type < 3) {
    *x1 = obstacle->x;
    *x2 = obstacle->x + obstacle->width;
    *y1 = obstacle->y;
    *y2 = obstacle->y + obstacle->height;
  } else if (obstacle->type == 3) {
    *x1 = obstacle->x;
    *x2 = obstacle->x + obstacle->width;
    *y1 = obstacle->y + (obstacle->height * 0.19);
    *y2 = obstacle->y + obstacle->height;
  } else if (obstacle->type > 3) {
    *x1 = obstacle->x + (obstacle->width * 0.15);
    *x2 = obstacle->x + obstacle->width;
    *y1 = obstacle->y;
    *y2 = obstacle->y + obstacle->height;
  }
}

void obstacle_destroy(Obstacle* obstacle)
{
  SDL_DestroyTexture((*obstacle)->texture);
  free(*obstacle);
}