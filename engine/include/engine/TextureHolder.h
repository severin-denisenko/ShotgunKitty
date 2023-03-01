//
// Created by Severin on 28.02.2023.
//

#ifndef SHOTGUNKITTY_TEXTUREHOLDER_H
#define SHOTGUNKITTY_TEXTUREHOLDER_H

#include <map>
#include <string>

#include "Renderer.h"
#include "Transform.h"

struct SDL_Texture;

namespace engine {

    class TextureHolder {
    public:
        explicit TextureHolder(Renderer& renderer);

        void Load(const std::string& file, const std::string& id);
        void Unload(const std::string& id);
        SDL_Texture* Get(const std::string& id);
        int getWidth(const std::string& id);
        int getHeight(const std::string& id);

        void Draw(const std::string& id) const;
        void Draw(const std::string& id, int x, int y, int w, int h) const;
        void Draw(const std::string& id, Transform transform) const;
        void Draw(const std::string& id, Transform transform, int mapWidth, int mapHeight, int index) const;

    private:
        Renderer& renderer;
        std::map<std::string, SDL_Texture*> map;
    };

} // engine

#endif //SHOTGUNKITTY_TEXTUREHOLDER_H
