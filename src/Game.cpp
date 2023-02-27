//
// Created by Severin on 27.02.2023.
//

#include "Game.h"

#include <SDL.h>

Game::Game() : widow(), renderer(widow) {

}

void Game::Events() {
    if (input.IsKeyPressed("Q"))
        Running = false;
    if (input.IsKeyPressed("F"))
        widow.toggleFullScreen();

    input.Clear();
}

void Game::Update() {
    input.Collect();
}

void Game::Render() {
    renderer.Update();
}
