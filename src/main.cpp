#include "Game.h"

int main() {
    Game game;

    while (game.Running){
        game.Events();
        game.Update();
        game.Render();
    }

    return 0;
}
