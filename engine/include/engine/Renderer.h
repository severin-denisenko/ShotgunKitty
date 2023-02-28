//
// Created by Severin on 27.02.2023.
//

#ifndef SHOTGUNKITTY_RENDERER_H
#define SHOTGUNKITTY_RENDERER_H

#include "Widow.h"

struct SDL_Renderer;

namespace engine {

    class Renderer {
    public:
        explicit Renderer(Widow& widow);
        ~Renderer();

        void Clear();
        void Show();

        SDL_Renderer* renderer;
    private:
        Widow& widow;
    };

} // engine

#endif //SHOTGUNKITTY_RENDERER_H
