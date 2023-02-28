//
// Created by Severin on 28.02.2023.
//

#include "engine/Entity.h"

namespace engine {
    Transform Entity::getWorldTransform() {
        Transform curr = transform;

        for (Entity* i = parent; i != nullptr; i = i->getPatent())
            curr = curr.add(i->transform);

        return curr;
    }

    Entity* Entity::getPatent() {
        return parent;
    }

    void Entity::addEntity(std::unique_ptr<Entity> entity) {
        entity->parent = this;
        children.push_back(std::move(entity));
    }

    void Entity::Update() {
        if (!created){
            Create();

            return;
        }

        for (auto& i: children) {
            i->Update();
        }

        updateCurrent();
    }

    void Entity::Create() {
        for (auto& i: children) {
            i->Create();
        }

        createCurrent();

        created = true;
    }

    void Entity::Render() {
        for (auto& i: children) {
            i->Render();
        }

        renderCurrent();
    }
} // engine