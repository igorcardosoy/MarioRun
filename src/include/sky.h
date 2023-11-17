#include "./utils.h"

typedef struct sky_type* Sky;

// Inicializa o céu (sky) e define sua posição e tamanho.
void sky_init(Sky* sky, SDL_Renderer* renderer);

// Anima o céu (sky) com sua velocidade. Sendo que gera um efeito de loop e da direita para a esquerda.
void sky_animate(Sky sky, SDL_Renderer* renderer, int width, int height, double speed);

// Destroi o céu (sky) e libera a memória alocada.
void sky_destroy(Sky* sky);