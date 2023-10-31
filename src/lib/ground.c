#include "../include/ground.h"


struct ground_type {
    int x, y;
    int width, height;
    SDL_Texture* texture;
};

void ground_init(Ground* ground, SDL_Renderer* renderer, int x, int y, int width, int height);

void ground_animate(Ground ground, SDL_Renderer* renderer, int width, int height, double speed);

void ground_destroy(Ground* ground);