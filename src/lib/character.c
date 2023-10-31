#include "../include/character.h"

struct character_type
{
    int x, y;
    int width, height;
    int gravity;
    bool is_dead;
    SDL_Texture *texture; // Por enquanto a textura indica uma imagem estatica, mas depois pode ser um vetor de texturas para animacao ou um gif.
    SDL_Texture *texture_dead;
};

void character_init(Character* character, SDL_Renderer* renderer,int x, int y, int width, int height);

void character_animate(Character character, SDL_Renderer* renderer, SDL_Window* window);

void character_jump(Character character, int height);

void character_fall(Character character, int height);

void character_get_colision(Character character, int* x1, int* x2, int* y1, int* y2);

int character_get_position_y(Character character);

void character_destroy(Character character);