#include "./main.h"

typedef struct character_type* Character;

// Função que detem o poder de iniciar o personagem do jogo. Recebe como argumento a posição X dele e a posição Y, sua largura(Width) e sua altura(Heigth), onde dentro da função esses dados são colocados como atributos do personagem.
void character_init(Character* character, SDL_Renderer* renderer, int width, int height);

// Função que detem o poder de desenhar o personagem na tela, sendo assim responsavel por animar o personagem e definir as animacoes caso o persona esteja pulando ou esteja agachado, e define tambem a gravidade do personagem. Recebe como argumento o personagem, o renderer e window.
void character_animate(Character character, SDL_Renderer* renderer, int width, int height);

// Função para fazer com que o personagem pule, sendo que, a altura do pula sera baseado no height atual da tela, recebendo como argumento o personagem e a altura.
void character_jump(Character character, int height);

// Função para fazer com que o personagem morra ou volte a vida.
void character_set_dead(Character character, bool is_dead);

// Função para fazer com que o personagem agache ou caso esteja no ar ele caia mais rapido, sendo que, a altura do agacha sera baseado no height atual da tela, recebendo como argumento o personagem e a altura.
void character_fall(Character character, int height);

// Função que retorna o calculo da colisão do personagem. Recebe como argumento o personagem.
void character_get_colision(Character character, double* x1, double* x2, double* y1, double* y2);

// Função para retornar a posição Y do personagem. Podendo ser utilizada para varios parametros.
int character_get_position_y(Character character);

// Função para destroir o personagem, sendo que, ela libera a memoria alocada para o personagem.
void character_destroy(Character* character);