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
        Widow();
        ~Widow();

        void toggleFullScreen();

        int width = 640;
        int height = 480;
        int windowedWidth = 640;
        int windowedHeight = 480;
        bool fullScreen = true;

        SDL_Window* window;
    };

} // engine

#endif //SHOTGUNKITTY_WIDOW_H
