#include "../include/mario_run.h"

struct game_type
{
    Sky sky;
    Ground ground;
    Character character;
    Obstacle obstacle;
    Queue queue;
    Text text;
    double speed;
    int score;
};

void game_init(Game* game);

void game_menu(Game game, bool is_dead);

void game_animate(Game game);

void game_run(Game game, int* quit);

void game_reset(Game game);

bool are_colliding(Character character, Obstacle obstacle);

void game_destroy(Game* game);