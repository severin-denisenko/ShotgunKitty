//
// Created by Severin on 01.03.2023.
//

#include "engine/Entities/TileMap.h"

#include <fstream>

#include "engine/Game.h"

namespace engine {
    void TileMap::Resize(Pos w, Pos h) {
        map.resize(h);

        for (auto& i : map)
            i.resize(w, -1);

        width = w;
        height = h;
    }

    void TileMap::Splice(Pos w, Pos h) {
        mapWidth = w;
        mapHeight = h;
    }

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

    void TileMap::renderCurrent() {
        Entity::renderCurrent();

        Pos w = game.textureHolder.getWidth(id) / mapWidth;
        Pos h = game.textureHolder.getHeight(id) / mapHeight;

        for (Pos i = 0; i < height; ++i) {
            for (Pos j = 0; j < width; ++j) {
                if(map[i][j] == -1)
                    continue;

                Transform tr = Transform({(float)j * w,(float)i * h, 0},
                                         {0, 0, 0},
                                         {1, 1, 1});

                game.textureHolder.Draw(id, tr.add(getWorldTransform()), mapWidth, mapHeight, map[i][j]);
            }
        }
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
} // engine