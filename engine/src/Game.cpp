//
// Created by Severin on 28.02.2023.
//

#include "engine/Game.h"

namespace engine {
    Game::Game(const std::string& name) : widow(name.c_str()), renderer(widow), textureHolder(renderer), root("root", *this), timer(60) {

    }

    void Game::Run() {
        Setup();

        while (Running){
            Update();
            Render();
        }

        Shutdown();
    }

    void Game::Update() {
        input.Collect();
        root.Update();
        input.Clear();
    }

    void Game::Render() {
        renderer.Clear();
        root.Render();
        renderer.Show();

        timer.Loop();
        timer.Wait();
    }
} // engine