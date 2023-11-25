#include "./utils.h"

#define BLACK 0, 0, 0, 255
#define WHITE 255, 255, 255, 255

typedef struct text_type* Text;

// Inicializa o texto (text) e define a fonte.
void text_init(Text* text);

// Renderiza o texto (text) na tela. Sendo que o texto é renderizado em uma posição (x, y), com um tamanho (width, height), com a fonte e tamanho indicada nos argumentos e com o texto a ser renderizado. 
void text_render(Text text, SDL_Renderer* renderer, int x, int y, int width, int height, int size, char* text_to_render, int r, int g, int b, int a);

// Destrói o texto (text), liberando a memória.
void text_destroy(Text* text);