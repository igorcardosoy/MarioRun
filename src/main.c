#include "./include/mario_run.h"

int main(int argc, char* argv[])
{
    Game game;
    bool quit = false;

    game_init(&game);

    game_run(game, &quit);

    return 0;
}
