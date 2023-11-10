#include "./include/mario_run.h"

int main(int argc, char* argv[])
{
    Game game;
    bool quit = false;

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    Mix_Init(MIX_INIT_MP3);
    TTF_Init();

    game_init(&game);

    while (!quit)
    {
        game_run(game, &quit);
    }

    return 0;
}
