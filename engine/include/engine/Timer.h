//
// Created by Severin on 28.02.2023.
//

#ifndef SHOTGUNKITTY_TIMER_H
#define SHOTGUNKITTY_TIMER_H

#include <cstdint>

namespace engine {

    class Timer {
    public:
        explicit Timer(uint64_t fps);

        void Loop();
        uint64_t GetDelta() const;
        void Wait() const;
    private:
        uint64_t first = 0;
        uint64_t second = 0;
        uint64_t fps;
    };

} // engine

#endif //SHOTGUNKITTY_TIMER_H
