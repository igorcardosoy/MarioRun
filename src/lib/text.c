#include "../include/text.h"

struct text_type {
  TTF_Font* font;
  SDL_Surface* surface;
  SDL_Texture* texture;
  SDL_Rect rect;
  SDL_Color color;
};

void text_init(Text* text)
{
  if (TTF_Init() < 0) {
    printf("TTF_Init: %s\n", TTF_GetError());
    exit(1);
  }

  *text = malloc(sizeof(struct text_type));
  if (*text != NULL) {
    (*text)->color = (SDL_Color){ 255, 255, 255, 255 };
  }
}

void text_render(Text text, SDL_Renderer* renderer, int x, int y, int width, int height, char* font, int size, char* text_to_render)
{
  text->rect = (SDL_Rect){ x, y, width, height };
  text->font = TTF_OpenFont(font, size);
  text->surface = TTF_RenderText_Solid(text->font, text_to_render, text->color);
  text->texture = SDL_CreateTextureFromSurface(renderer, text->surface);
  SDL_RenderCopy(renderer, text->texture, NULL, &text->rect);
}

void text_destroy(Text* text)
{
  SDL_DestroyTexture((*text)->texture);
  TTF_CloseFont((*text)->font);
  free(*text);
}