//
// Created by Severin on 01.03.2023.
//

#include "engine/Entities/TileMap.h"
#include "engine/Game.h"

#include <fstream>

namespace engine {
    Index& TileMap::operator()(Pos x, Pos y) {
        if (x >= width || y >= height)
            throw std::runtime_error("Index out of bounds in TileMap");

        return map[y][x];
    }

    const Index& TileMap::operator()(Pos x, Pos y) const {
        if (x >= width || y >= height)
            throw std::runtime_error("Index out of bounds in TileMap");

        return map[y][x];
    }

    void TileMap::Load(const std::string& filename) {
        std::ifstream file(filename);

        file >> width;
        file >> height;

        Resize(width, height);

        for (Pos i = 0; i < height; ++i) {
            for (Pos j = 0; j < width; ++j) {
                file >> map[i][j];
            }
        }
    }

    void TileMap::Save(const std::string& filename) {
        std::ofstream file(filename);

        file << width << " " << height << std::endl;

        for (Pos i = 0; i < height; ++i) {
            for (Pos j = 0; j < width; ++j) {
                file << map[i][j] << " ";
            }
            file << std::endl;
        }
    }

    void TileMap::Resize(Pos w, Pos h) {
        map.resize(h);

        for (auto& i : map)
            i.resize(w, -1);

        width = w;
        height = h;
    }

    void TileMap::renderCurrent() {
        Entity::renderCurrent();

        for (Pos i = 0; i < height; ++i) {
            for (Pos j = 0; j < width; ++j) {
                if(map[i][j] == -1)
                    continue;

                Transform tr = Transform({(float)j * game.textureHolder.getWidth(ids[map[i][j]]),
                                          (float)i * game.textureHolder.getHeight(ids[map[i][j]]), 0},
                                         {0, 0, 0},
                                         {1, 1, 1});

                game.textureHolder.Draw(ids[map[i][j]], tr.add(getWorldTransform()));
            }
        }
    }
} // engine