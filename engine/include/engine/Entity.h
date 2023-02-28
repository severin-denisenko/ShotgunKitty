//
// Created by Severin on 28.02.2023.
//

#ifndef SHOTGUNKITTY_ENTITY_H
#define SHOTGUNKITTY_ENTITY_H

#include <memory>
#include <utility>
#include <vector>
#include <string>

#include "Transform.h"

namespace engine {
    class Game;

    class Entity {
    public:
        explicit Entity(std::string name, Game& game, Entity* parent = nullptr) : name(std::move(name)), game(game), parent(parent) {}
        virtual ~Entity() = default;

        Transform getWorldTransform();
        Entity* getPatent();

        void addEntity(std::unique_ptr<Entity> entity);

        void Update();
        void Create();
        void Render();

        Transform transform;
        std::string name;
    protected:
        virtual void updateCurrent() {}
        virtual void createCurrent() {}
        virtual void renderCurrent() {}

        Game& game;
    private:
        bool created = false;
        std::vector<std::unique_ptr<Entity>> children;
        Entity* parent;
    };

} // engine

#endif //SHOTGUNKITTY_ENTITY_H
