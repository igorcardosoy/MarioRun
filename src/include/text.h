#include "./main.h"

typedef struct text_type* Text;

// Inicializa o texto (text) e define a fonte.
void text_init(Text* text, char* font);

// Renderiza o texto (text) na tela. Sendo que o texto é renderizado em uma posição (x, y), com um tamanho (width, height), com a fonte e tamanho indicada nos argumentos e com o texto a ser renderizado. 
void text_render(Text text, SDL_Renderer* renderer, int x, int y, int width, int height, char* font, int size, char* text_to_render)

// Destroi o texto (text) e libera a memória alocada.
void text_destroy(Text* text);