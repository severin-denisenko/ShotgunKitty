//
// Created by Severin on 27.02.2023.
//

#include "engine/Renderer.h"

#include <stdexcept>

#include <SDL.h>

namespace engine {
    Renderer::Renderer(Widow& window) {
        renderer = SDL_CreateRenderer(window.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if (!renderer)
            throw std::runtime_error("Can't create renderer from SDL window");

        SDL_SetRenderDrawColor(renderer, 20, 100, 50, 255);
    }

    void Renderer::Update() {
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    Renderer::~Renderer() {
        SDL_DestroyRenderer(renderer);
    }
} // engine