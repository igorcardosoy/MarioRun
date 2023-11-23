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
  *text = malloc(sizeof(struct text_type));
  if (*text != NULL) {
  } else {
    printf("Erro ao alocar texto!\n");
  }
}

void text_render(Text text, SDL_Renderer* renderer, int x, int y, int width, int height, char* font, int size, char* text_to_render, int r, int g, int b, int a)
{

  text->color = (SDL_Color){ r, g, b, a };
  text->rect = (SDL_Rect){ x, y, width * 0.10, height * 0.10 };
  text->font = TTF_OpenFont(font, size);
  text->surface = TTF_RenderText_Solid(text->font, text_to_render, text->color);
  text->texture = SDL_CreateTextureFromSurface(renderer, text->surface);
  SDL_RenderCopy(renderer, text->texture, NULL, &text->rect);

  SDL_FreeSurface(text->surface);
  TTF_CloseFont(text->font);
  SDL_DestroyTexture(text->texture);
}