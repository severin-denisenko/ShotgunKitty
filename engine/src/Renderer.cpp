//
// Created by Severin on 27.02.2023.
//

#include "engine/Renderer.h"

#include <stdexcept>

#include <SDL.h>

namespace engine {
    Renderer::Renderer(Widow& window) : widow(window) {
        renderer = SDL_CreateRenderer(window.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if (!renderer)
            throw std::runtime_error("Can't create renderer from SDL window");

        SDL_RenderSetLogicalSize(renderer, window.windowedWidth, window.windowedHeight);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }

    void Renderer::Clear() {
        SDL_RenderClear(renderer);
    }

    Renderer::~Renderer() {
        SDL_DestroyRenderer(renderer);
    }

    void Renderer::Show() {
        SDL_RenderPresent(renderer);
    }
} // engine