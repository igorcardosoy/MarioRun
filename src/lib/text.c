#include "../include/text.h"

struct text_type {
  TTF_Font* font;
  char* font_path;
  SDL_Surface* surface;
  SDL_Texture* texture;
  SDL_Rect rect;
  SDL_Color color;
};

void text_init(Text* text)
{
  *text = malloc(sizeof(struct text_type));
  if (*text != NULL) {
    (*text)->font_path = malloc(sizeof(char) * 45);
    snprintf((*text)->font_path, 45, "src/assets/fonts/font.ttf");
    (*text)->surface = NULL;
    (*text)->texture = NULL;
    (*text)->rect = (SDL_Rect){ 0, 0, 0, 0 };
    (*text)->color = (SDL_Color){ 0, 0, 0, 0 };
  } else {
    printf("Erro ao alocar texto!\n");
  }
}

void text_render(Text text, SDL_Renderer* renderer, int x, int y, int width, int height, int size, char* text_to_render, int r, int g, int b, int a)
{
  text->font = TTF_OpenFont(text->font_path, size);
  text->color = (SDL_Color){ r, g, b, a };
  text->rect = (SDL_Rect){ x, y, width * 0.10, height * 0.10 };
  text->surface = TTF_RenderText_Solid(text->font, text_to_render, text->color);
  text->texture = SDL_CreateTextureFromSurface(renderer, text->surface);
  SDL_RenderCopy(renderer, text->texture, NULL, &text->rect);

  TTF_CloseFont(text->font);
  SDL_FreeSurface(text->surface);
  SDL_DestroyTexture(text->texture);
}

void text_destroy(Text* text)
{
  free((*text)->font_path);
  free(*text);
  *text = NULL;
}