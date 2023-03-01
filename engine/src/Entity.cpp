//
// Created by Severin on 28.02.2023.
//

#include "engine/Entity.h"

namespace engine {
    Transform Entity::getWorldTransform() {
        Transform curr = transform;

        for (Entity* i = parent; i != nullptr; i = i->getParent())
            curr = curr.add(i->transform);

        return curr;
    }

    Entity* Entity::getParent() {
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

    Entity* Entity::getChildByName(const std::string& name) {
        auto find = std::find_if(children.begin(), children.end(), [&name](std::unique_ptr<Entity>& entity){
            return entity->name == name;
        });

        if (find == children.end())
            throw std::runtime_error("Can't find child: " + name);

        return find->get();
    }
} // engine