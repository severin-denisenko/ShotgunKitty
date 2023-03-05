//
// Created by Severin on 27.02.2023.
//

#ifndef SHOTGUNKITTY_WIDOW_H
#define SHOTGUNKITTY_WIDOW_H

#include <cstdint>

struct SDL_Window;

namespace engine {

    class Widow {
    public:
        Widow(const char* name);
        ~Widow();

        void toggleFullScreen();

        int width = 1920;
        int height = 1080;
        int windowedWidth = 1920;
        int windowedHeight = 1080;
        bool fullScreen = true;

        SDL_Window* window;
    };

} // engine

#endif //SHOTGUNKITTY_WIDOW_H
