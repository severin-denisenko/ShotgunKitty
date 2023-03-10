//
// Created by Severin on 01.03.2023.
//

#ifndef SHOTGUNKITTY_TILEMAP_H
#define SHOTGUNKITTY_TILEMAP_H

#include "engine/Entity.h"

namespace engine {

    using Index = int32_t;
    using Pos = uint32_t;

    class TileMap : public Entity{
    public:
        TileMap(std::string name, Game& game, Entity* parent, std::string id) :
        Entity(std::move(name), game, parent), id(std::move(id)) {}

        void Load(const std::string& filename);
        void Save(const std::string& filename);

        Index& operator()(Pos x, Pos y);
        const Index& operator()(Pos x, Pos y) const;

        void Resize(Pos w, Pos h);
        void Splice(Pos w, Pos h);
    protected:
        void renderCurrent() override;

    private:
        Pos width = 0;
        Pos height = 0;

        std::vector<std::vector<Index>> map;

        std::string id;
        Pos mapWidth = 1;
        Pos mapHeight = 1;
    };

} // engine

#endif //SHOTGUNKITTY_TILEMAP_H
