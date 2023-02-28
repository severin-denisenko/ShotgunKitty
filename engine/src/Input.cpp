//
// Created by Severin on 28.02.2023.
//

#include "engine/Input.h"

#include <SDL.h>

namespace engine{

    Input::Input() {

    }

    bool Input::IsKeyPressed(const char* key) {
        for (auto i = events.begin(); i != events.end(); ++i) {
            if ((*i)->type == SDL_KEYDOWN && (*i)->key.keysym.scancode == SDL_GetScancodeFromName(key)){
                events.erase(i);
                return true;
            }
        }

        return false;
    }

    void Input::Collect() {
        auto * e = new SDL_Event();

        while(SDL_PollEvent(e) > 0)
        {
            events.push_back(e);
            e = new SDL_Event();
        }

        delete e;
    }

    void Input::Clear() {
        events.clear();
    }

    bool Input::IsExit() {
        for (auto i = events.begin(); i != events.end(); ++i) {
            if ((*i)->type == SDL_QUIT){
                events.erase(i);
                return true;
            }
        }

        return false;
    }
}
