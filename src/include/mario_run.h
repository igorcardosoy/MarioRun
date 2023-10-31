#include "./main.h"
#include "./obstacle.h"
#include "./queue.h"
#include "./sky.h"
#include "./ground.h"
#include "./character.h"   
#include "./text.h"

typedef struct game_type* Game;

// Inicializa o jogo (game).
void game_init(Game* game);

// Mostra o menu na tela.
void game_menu(Game game, bool is_dead);

// Anima o jogo e todos os seus elementos.
void game_animate(Game game);

// Detecta os eventos do jogo, como teclas.
void game_events(Game game);

// Executa o jogo em loop até a morte do player.
void game_run(Game game, int* quit);

// Reseta o jogo e todos os paramestros de outros TADs.
void game_reset(Game game);

// Verifica se o player está colidindo com algum obstáculo.
bool are_colliding(Character character, Obstacle obstacle);

// Destroi o jogo (game) e libera a memória alocada.
void game_destroy(Game* game);