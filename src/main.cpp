#include "Game.h"

int main() {
    Game game;

    game.Setup();

    while (game.Running){
        game.Update();
        game.Render();
    }

    game.Shutdown();

    return 0;
}
