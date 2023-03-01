//
// Created by Severin on 28.02.2023.
//

#ifndef SHOTGUNKITTY_TRANSFORM_H
#define SHOTGUNKITTY_TRANSFORM_H

namespace engine{
    struct Vector3{
        float x;
        float y;
        float z;
    };

    Vector3 operator+(const Vector3& a, const Vector3& b);
    Vector3 operator*(const Vector3& a, const Vector3& b);

    class Transform{
    public:
        Transform(Vector3 position, Vector3 rotation, Vector3 scale) : position(position),
                                                                       rotation(rotation), scale(scale) {}

        Transform() = default;

        Transform add(const Transform& other);

        Vector3 position {0, 0, 0};
        Vector3 rotation {0, 0, 0};
        Vector3 scale {1, 1, 1};
    };
}

#endif //SHOTGUNKITTY_TRANSFORM_H
