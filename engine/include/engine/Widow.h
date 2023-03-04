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

        int width = 256;
        int height = 160;
        int windowedWidth = 256;
        int windowedHeight = 160;
        bool fullScreen = true;

        SDL_Window* window;
    };

} // engine

#endif //SHOTGUNKITTY_WIDOW_H
