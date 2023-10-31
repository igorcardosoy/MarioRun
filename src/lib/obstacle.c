#include "../include/obstacle.h"

struct obstacle_type {
    int x, y;
    int width, height;
    SDL_Texture* texture;
};

void obstacle_init(Obstacle* obstacle, SDL_Renderer* renderer, int x, int y, int width, int height, int type)
{
    *obstacle = malloc(sizeof(struct obstacle_type));

    if (*obstacle != NULL) {
        (*obstacle)->x = x;
        (*obstacle)->y = y;
        (*obstacle)->width = width;
        (*obstacle)->height = height;

        char path[50];
        sprintf(path, "assets/images/obstacle%d.png", type);
        (*obstacle)->texture = IMG_LoadTexture(renderer, path);
    } else {
        printf("Erro ao alocar memoria para o obstaculo!\n");
    }
}

void obstacle_animate(Obstacle obstacle, SDL_Renderer* renderer, int width, int height, double speed);

int obstacle_get_position_x(Obstacle obstacle);

void obstacle_get_colision(Obstacle obstacle, int* x1, int* x2, int* y1, int* y2);

void obstacle_destroy(Obstacle* obstacle);