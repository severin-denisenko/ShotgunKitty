//
// Created by Severin on 27.02.2023.
//

#include "engine/Widow.h"

#include <stdexcept>

#include <SDL.h>

namespace engine {
    Widow::Widow() {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
            throw std::runtime_error("Can't initialize SDL");

        window = SDL_CreateWindow("SDL2 Window",
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  width, height,
                                  SDL_WINDOW_FULLSCREEN);

        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);

        if (!window)
            throw std::runtime_error("Can't create SDL window");

        SDL_ShowCursor(SDL_FALSE);
    }

    Widow::~Widow() {
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void Widow::toggleFullScreen() {
        fullScreen = !fullScreen;
        if (fullScreen){
            int displayIndex = SDL_GetWindowDisplayIndex(window);
            SDL_Rect displayBounds;
            SDL_GetDisplayBounds(displayIndex, &displayBounds);
            width = displayBounds.w;
            height = displayBounds.h;

            SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
            SDL_ShowCursor(SDL_FALSE);
        } else {
            width = windowedWidth;
            height = windowedHeight;
            SDL_SetWindowFullscreen(window, SDL_FALSE);
            SDL_ShowCursor(SDL_TRUE);
        }
    }

} // engine