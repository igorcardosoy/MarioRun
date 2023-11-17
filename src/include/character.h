#include "./utils.h"

typedef struct character_type* Character;

// Função que detem o poder de iniciar o personagem do jogo. Recebe como argumento a posição X dele e a posição Y, sua largura(Width) e sua altura(Heigth), onde dentro da função esses dados são colocados como atributos do personagem.
void character_init(Character* character, SDL_Renderer* renderer, int width, int height);

// Função que detem o poder de desenhar o personagem na tela, sendo assim responsavel por animar o personagem e definir as animacoes caso o persona esteja pulando ou esteja agachado, e define tambem a gravidade do personagem. Recebe como argumento o personagem, o renderer e window.
void character_animate(Character character, SDL_Renderer* renderer, int width, int height, int speed);

// Função para fazer com que o personagem pule, sendo que, receben como argumento o personagem.
void character_jump(Character character);

// Função para verificar se o personagem pode pular, sendo que, ela retorna um booleano, recebendo como argumento o personagem.
bool character_can_jump(Character character);

// Função para tocar o som do pulo do personagem, recebendo como argumento o personagem.
void character_jump_sound(Character character);

// Função para fazer com que o personagem morra ou volte a vida.
void character_set_dead(Character character, bool is_dead);

// Função para verificar se o personagem esta morto, recebendo como argumento o personagem.
bool character_is_dead(Character character);

// Função para verificar se o personagem esta na tela, recebendo como argumento o personagem e a altura.
bool character_is_ondisplay(Character character, int height);

// Função para fazer com que o personagem agache ou caso esteja no ar ele caia mais rapido, sendo que, a altura do agacha sera baseado no height atual da tela, recebendo como argumento o personagem e a altura.
void character_fall(Character character, int height);

// Função para setar se o personagem esta caindo ou não, recebendo como argumento o personagem e um bool de quer que o personagem caia ou não.
void character_set_falling(Character character, bool is_falling);

// Função para fazer com que a textura do personagem mude para a textura de agachado, recebendo como argumento o personagem, o renderer e um bool de quer que o personagem agache ou não.
void character_crouch(Character character, bool is_crouched);

// Função para verificar se o personagem esta agachado, recebendo como argumento o personagem.
bool character_is_crouched(Character character);

// Função que retorna o calculo da colisão do personagem. Recebe como argumento o personagem.
void character_get_colision(Character character, int* x1, int* x2, int* y1, int* y2);

// Função para retornar a posição Y do personagem. Podendo ser utilizada para varios parametros.
int character_get_position_y(Character character);

// Função para destroir o personagem, sendo que, ela libera a memoria alocada para o personagem.
void character_destroy(Character* character);