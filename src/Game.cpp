//
// Created by Severin on 27.02.2023.
//

#include "Game.h"

Game::Game() : widow("DeathKitty"), renderer(widow), textureHolder(renderer), root("root"), timer(60) {

}

void Game::Update() {
    input.Collect();

    if (input.IsKeyPressed("Q"))
        Running = false;
    if (input.IsKeyPressed("F"))
        widow.toggleFullScreen();
    if (input.IsExit())
        Running = false;

    root.Update();

    input.Clear();

    timer.Loop();
    timer.Wait();
}

void Game::Render() {
    renderer.Clear();

    textureHolder.Draw("Background", 0, 0, widow.height, widow.height);

    renderer.Show();
}

void Game::Setup() {
    textureHolder.Load("assets/hello.png", "Background");
}

void Game::Shutdown() {
    textureHolder.Unload("Background");
}
