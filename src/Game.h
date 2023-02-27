//
// Created by Severin on 27.02.2023.
//

#ifndef SHOTGUNKITTY_GAME_H
#define SHOTGUNKITTY_GAME_H

#include <engine/Widow.h>
#include <engine/Renderer.h>
#include <engine/Input.h>

class Game {
public:
    Game();

    void Events();
    void Update();
    void Render();

    bool Running = true;
private:
    engine::Widow widow;
    engine::Renderer renderer;
    engine::Input input;
};


#endif //SHOTGUNKITTY_GAME_H
