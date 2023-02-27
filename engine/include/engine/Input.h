//
// Created by Severin on 28.02.2023.
//

#ifndef SHOTGUNKITTY_INPUT_H
#define SHOTGUNKITTY_INPUT_H

#include <list>

union SDL_Event;

namespace engine{
    class Input {
    public:
        Input();

        void Collect();
        void Clear();

        bool IsKeyPressed(const char* key);
    private:
        std::list<SDL_Event*> events;
    };
}



#endif //SHOTGUNKITTY_INPUT_H
