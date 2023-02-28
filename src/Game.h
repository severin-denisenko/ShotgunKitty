//
// Created by Severin on 27.02.2023.
//

#ifndef SHOTGUNKITTY_GAME_H
#define SHOTGUNKITTY_GAME_H

#include <engine/Widow.h>
#include <engine/Renderer.h>
#include <engine/Input.h>
#include <engine/TextureHolder.h>
#include <engine/Entity.h>

class Game {
public:
    Game();

    void Setup();
    void Shutdown();
    void Update();
    void Render();

    bool Running = true;

    engine::Widow widow;
    engine::Renderer renderer;
    engine::Input input;
    engine::TextureHolder textureHolder;
    engine::Entity root;
};


#endif //SHOTGUNKITTY_GAME_H
