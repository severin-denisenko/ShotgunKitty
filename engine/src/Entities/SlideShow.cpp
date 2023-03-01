//
// Created by Severin on 01.03.2023.
//

#include "engine/Entities/SlideShow.h"
#include "engine/Game.h"

namespace engine {
    void SlideShow::renderCurrent() {
        Entity::renderCurrent();

        game.textureHolder.Draw(ids[frame % ids.size()], Entity::getWorldTransform());
    }

    void SlideShow::updateCurrent() {
        Entity::updateCurrent();

        i++;

        if (i % speed == 0)
            frame++;
    }
} // engine