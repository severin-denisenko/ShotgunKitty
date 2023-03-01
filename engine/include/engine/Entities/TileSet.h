//
// Created by Severin on 01.03.2023.
//

#ifndef SHOTGUNKITTY_TILESET_H
#define SHOTGUNKITTY_TILESET_H

#include "engine/Entity.h"

#include <map>
#include <utility>

namespace engine {

    using Index = int32_t;
    using Pos = uint32_t;

    class TileSet : public Entity{
    public:
        TileSet(std::string name, Game& game, Entity* parent, std::vector<std::string> ids) :
        Entity(std::move(name), game, parent), ids(std::move(ids)) {}

        void Load(const std::string& filename);
        void Save(const std::string& filename);

        Index& operator()(Pos x, Pos y);
        const Index& operator()(Pos x, Pos y) const;

        void Resize(Pos w, Pos h);

    protected:
        void renderCurrent() override;

    private:
        Pos width = 0;
        Pos height = 0;

        std::vector<std::vector<Index>> map;
        std::vector<std::string> ids;
    };

} // engine

#endif //SHOTGUNKITTY_TILESET_H
