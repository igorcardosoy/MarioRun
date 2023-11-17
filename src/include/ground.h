#include "./utils.h"

typedef struct ground_type* Ground;

// Inicializa o chão (ground) e define sua posição e tamanho.
void ground_init(Ground* ground, SDL_Renderer* renderer);

// Anima o chão (ground) com sua velocidade. Sendo que gera um efeito de loop e da direita para a esquerda.
void ground_animate(Ground ground, SDL_Renderer* renderer, int width, int height, double speed);

// Destroi o chão (ground) e libera a memória alocada.
void ground_destroy(Ground* ground);