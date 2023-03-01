//
// Created by Severin on 01.03.2023.
//

#ifndef SHOTGUNKITTY_SLIDESHOW_H
#define SHOTGUNKITTY_SLIDESHOW_H

#include <utility>

#include "engine/Entity.h"

namespace engine {

    class SlideShow : public Entity{
    public:
        SlideShow(std::string name, Game& game, Entity* parent, std::vector<std::string> ids) : Entity(std::move(name), game, parent), ids(std::move(ids)) {}

        int speed = 1;
    protected:
        void renderCurrent() override;
        void updateCurrent() override;
    private:
        std::vector<std::string> ids;
        uint32_t i = 0;
        uint32_t frame = 0;
    };

} // engine

#endif //SHOTGUNKITTY_SLIDESHOW_H
