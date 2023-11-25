#include "./utils.h"
#include "./obstacle.h"
#include "./queue.h"
#include "./sky.h"
#include "./ground.h"
#include "./character.h"   
#include "./text.h"
#include "./ranking.h"

#define FRAME_RATE 144
#define FRAME_TIME 1000 / FRAME_RATE

typedef struct game_type* Game;

// Inicializa o jogo (game).
void game_init(Game* game);

// Mostra a tela de ranking na tela.
bool game_ranking(Game game);

// Mostra o menu na tela.
bool game_menu(Game game, bool is_dead);

// Colocar os textos do menu para serem renderizados. Dependendo do valor de is_dead, o texto de "Game Over" será renderizado.
void game_menu_texts(Game game, bool is_dead, bool is_greater);

// Colocar os textos do menu de morte para serem renderizados. Dependendo do valor de is_greater, o texto de "Adicionar no ranking" será renderizado.
void game_menu_dead(Game game, bool is_greater, bool add_to_ranking);

// Pausa o jogo e oferece algumas opções.
void game_pause(Game game);

// Anima o jogo e todos os seus elementos.
void game_animate(Game game, bool render);

// Anima um frame fixo de fade.
void game_fade(Game game, int i);

// Anima um fade de um valor inicial até um valor final. Dependendo do valor de fade_in, o fade será de preto para transparente ou de transparente para preto.
void game_do_fade(Game game, int initial, int end, bool fade_in);

// Desenha um frame do jogo na tela.
void game_frame(Game game, bool* quit);

// Detecta os eventos do jogo, como teclas.
bool game_events(Game game);

// Executa o jogo em loop até o player decidir sair do jogo.
void game_run(Game game);

// Reseta o jogo e todos os paramestros de outros TADs.
void game_reset(Game game);

// Verifica se o player está colidindo com algum obstáculo.
bool are_colliding(Character character, Obstacle obstacle);

// Destroi o jogo (game) e libera a memória alocada.
void game_destroy(Game* game);