//
// Created by Severin on 28.02.2023.
//

#include "engine/Transform.h"


engine::Transform engine::Transform::add(engine::Transform& other) {
    return {this->position + other.position,
            this->rotation + other.rotation,
            this->scale * other.scale};
}

engine::Vector3 engine::operator+(engine::Vector3& a, engine::Vector3& b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

engine::Vector3 engine::operator*(engine::Vector3& a, engine::Vector3& b) {
    return {a.x * b.x, a.y * b.y, a.z * b.z};
}
