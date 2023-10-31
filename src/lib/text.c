#include "../include/text.h"

struct text_type {
    TTF_Font* font;
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Rect rect;
    SDL_Color color;
};

void text_init(Text* text, char* font);

void text_render(Text text, SDL_Renderer* renderer, int x, int y, int width, int height, char* text_to_render);

void text_destroy(Text* text);