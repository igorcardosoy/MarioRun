#include "./utils.h"


typedef struct obstacle_type* Obstacle;

// Função para inciar o obstaculo, recebe como parametro o renderizador, a posição x e y, a largura, a altura e o tipo. Podendo ser do tipo 1, 2, 3, 4, 5, 6. Ele aloca a memoria para o obstaculo e retorna o mesmo por referencia.
void obstacle_init(Obstacle* obstacle, SDL_Renderer* renderer, int width, int height, int type);

// Função para desenhar o obstaculo e ele andar, da direira para esquerda, a uma velocidade que é recebida como parametro, recebe como parametro o renderizador, a tela e o obstaculo. Retorna o obstaculo e fazer com que ele ande.
void obstacle_animate(Obstacle obstacle, SDL_Renderer* renderer, int width, int height, double speed);

// Retorna a posição X do obstaculo.
int obstacle_get_position_x(Obstacle obstacle);

// Retorna a largura do obstaculo.
int obstacle_get_width(Obstacle obstacle);

// Função para resetar a posição do obstaculo, recebe como parametro o obstaculo, a largura da tela. Fazendo com que o obstaculo volte para a direita da tela mesmo com a tela mudando de tamanho.
void obstacle_reset_position(Obstacle obstacle, int width, int height);

// Função para fazer o calculo da colisão do obstaculo.
void obstacle_get_colision(Obstacle obstacle, int* x1, int* x2, int* y1, int* y2);

// Função para liberar a memoria alocada para o obstaculo.
void obstacle_destroy(Obstacle* obstacle);