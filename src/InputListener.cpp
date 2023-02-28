//
// Created by Severin on 28.02.2023.
//

#include "InputListener.h"

#include "engine/Game.h"

void InputListener::updateCurrent() {
    Entity::updateCurrent();

    if (game.input.IsExit())
        game.Running = false;
    if (game.input.IsKeyPressed("F"))
        game.widow.toggleFullScreen();
}
