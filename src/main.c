#include "./include/mario_run.h"

int main(int argc, char* argv[])
{
    Game game;
    bool quit = false;


    game_init(&game);

    while (!quit)
    {
        game_run(game, &quit);
    }

    return 0;
}
