#include "../include/sky.h"

struct sky_type {
    int x, y;
    int width, height;
    SDL_Texture* texture;
};

void sky_init(Sky* sky, SDL_Renderer* renderer, int x, int y, int width, int height);

void sky_animate(Sky sky, SDL_Renderer* renderer, int width, int height, double speed);

void sky_destroy(Sky* sky);