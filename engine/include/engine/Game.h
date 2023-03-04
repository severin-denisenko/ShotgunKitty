//
// Created by Severin on 28.02.2023.
//

#ifndef SHOTGUNKITTY_GAME_H
#define SHOTGUNKITTY_GAME_H

#include <string>

#include "Widow.h"
#include "Renderer.h"
#include "Input.h"
#include "TextureHolder.h"
#include "AudioHolder.h"
#include "Entity.h"
#include "Timer.h"

namespace engine {

    class Game {
    public:
        explicit Game(const std::string& name);

        void Run();

        engine::Widow widow;
        engine::Renderer renderer;
        engine::Input input;
        engine::TextureHolder textureHolder;
        engine::Entity root;
        engine::Timer timer;
        engine::AudioHolder audioHolder;

        bool Running = true;

    protected:
        virtual void Setup() {}
        virtual void Shutdown() {}

        virtual void Update();
        virtual void Render();
    };

} // engine

#endif //SHOTGUNKITTY_GAME_H
