//
// Created by Severin on 28.02.2023.
//

#include "engine/Timer.h"

#include <SDL.h>

namespace engine {
    void Timer::Loop() {
        first = second;
        second = SDL_GetTicks64();
    }

    Timer::Timer(uint64_t fps) : fps(fps) {

    }

    uint64_t Timer::GetDelta() const{
        return second - first;
    }

    void Timer::Wait() const{
        if (1000 / fps > GetDelta()){
            SDL_Delay(1000 / fps - GetDelta());
        }
    }
} // engine