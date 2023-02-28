//
// Created by Severin on 28.02.2023.
//

#ifndef SHOTGUNKITTY_INPUTLISTENER_H
#define SHOTGUNKITTY_INPUTLISTENER_H

#include <engine/Entity.h>

#include <utility>

class InputListener : public engine::Entity{
public:
    InputListener(std::string name, engine::Game& game, Entity* parent = nullptr) : engine::Entity(std::move(name), game, parent) {}

    void updateCurrent() override;
};


#endif //SHOTGUNKITTY_INPUTLISTENER_H
