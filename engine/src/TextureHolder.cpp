//
// Created by Severin on 28.02.2023.
//

#include "engine/TextureHolder.h"

#include <cmath>

#include <SDL.h>
#include <SDL_image.h>

namespace engine {
    TextureHolder::TextureHolder(Renderer& renderer) : renderer(renderer) {

    }

    void TextureHolder::Load(const std::string& file, const std::string& id) {
        SDL_Surface* surface = IMG_Load(file.c_str());
        if(!surface)
            throw std::runtime_error("Can't load surface with filename " + file);

        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer.renderer, surface);
        SDL_FreeSurface(surface);

        if(!texture)
            throw std::runtime_error("Can't load texture with filename " + file);

        map[id] = texture;
    }

    SDL_Texture* TextureHolder::Get(const std::string& id) {
        return map.at(id);
    }

    void TextureHolder::Unload(const std::string& id) {
        SDL_DestroyTexture(map.at(id));
        map.erase(id);
    }

    void TextureHolder::Draw(const std::string& id) const {
        SDL_Rect srcRect;
        SDL_Rect distRect;

        srcRect.x = 0;
        srcRect.y = 0;
        SDL_QueryTexture(map.at(id), nullptr, nullptr, &srcRect.w, &srcRect.h);
        distRect = srcRect;

        SDL_RenderCopyEx(renderer.renderer, map.at(id), &srcRect, &distRect,
                         0, nullptr, SDL_FLIP_NONE);
    }

    void TextureHolder::Draw(const std::string& id, int x, int y, int w, int h) const {
        SDL_Rect srcRect;
        SDL_Rect distRect;

        srcRect.x = 0;
        srcRect.y = 0;
        SDL_QueryTexture(map.at(id), nullptr, nullptr, &srcRect.w, &srcRect.h);
        distRect.x = x;
        distRect.y = y;
        distRect.w = w;
        distRect.h = h;

        SDL_RenderCopyEx(renderer.renderer, map.at(id), &srcRect, &distRect,
                         0, nullptr, SDL_FLIP_NONE);
    }

    void TextureHolder::Draw(const std::string& id, Transform transform) const{
        SDL_Rect srcRect;
        SDL_Rect distRect;

        srcRect.x = 0;
        srcRect.y = 0;
        SDL_QueryTexture(map.at(id), nullptr, nullptr, &srcRect.w, &srcRect.h);
        distRect = srcRect;

        distRect.x += transform.position.x;
        distRect.y += transform.position.y;
        distRect.w *= transform.scale.x;
        distRect.h *= transform.scale.y;

        SDL_RenderCopyEx(renderer.renderer, map.at(id), &srcRect, &distRect,
                         transform.rotation.z, nullptr, SDL_FLIP_NONE);
    }

    int TextureHolder::getWidth(const std::string& id) {
        int res;
        SDL_QueryTexture(map.at(id), nullptr, nullptr, &res, nullptr);
        return res;
    }

    int TextureHolder::getHeight(const std::string& id) {
        int res;
        SDL_QueryTexture(map.at(id), nullptr, nullptr, nullptr, &res);
        return res;
    }

    void TextureHolder::Draw(const std::string& id, Transform transform, int mapWidth, int mapHeight, int index) const{
        SDL_Rect srcRect;
        SDL_Rect distRect;

        SDL_FRect srcRectF;
        SDL_FRect distRectF;

        SDL_QueryTexture(map.at(id), nullptr, nullptr, &srcRect.w, &srcRect.h);
        srcRectF.w = (float)srcRect.w;
        srcRectF.h = (float)srcRect.h;

        srcRectF.w /= (float)mapWidth;
        srcRectF.h /= (float)mapHeight;
        srcRectF.x = srcRectF.w * (float)(index % mapWidth);
        srcRectF.y = srcRectF.h * (float)(index / mapWidth);

        srcRect.w = std::floor(srcRectF.w);
        srcRect.h = std::floor(srcRectF.h);
        srcRect.x = std::ceil(srcRectF.x);
        srcRect.y = std::ceil(srcRectF.y);

        distRectF.x = 0;
        distRectF.y = 0;
        distRectF.w = (float)srcRect.w;
        distRectF.h = (float)srcRect.h;

        distRectF.x += transform.position.x;
        distRectF.y += transform.position.y;
        distRectF.w *= transform.scale.x;
        distRectF.h *= transform.scale.y;

        distRect.x = std::floor(distRectF.x);
        distRect.y = std::floor(distRectF.y);
        distRect.w = std::ceil(distRectF.w);
        distRect.h = std::ceil(distRectF.h);

        SDL_RenderCopyEx(renderer.renderer, map.at(id), &srcRect, &distRect,
                         transform.rotation.z, nullptr, SDL_FLIP_NONE);
    }
} // engine