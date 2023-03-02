//
// Created by Severin on 28.02.2023.
//

#include "KillerKitty.h"

#include "InputListener.h"
#include <engine/Entities/TileMap.h>

void KillerKitty::Setup() {
    Game::Setup();

    root.addEntity(std::make_unique<InputListener>("Exit", *this, &root));

    textureHolder.Load("assets/Tiles/Tiles.png", "Tiles");

    auto* map = new engine::TileMap("Tiles", *this, &root, "Tiles");
    map->Load("assets/Tiles/Tilemap.tilemap");

    root.addEntity(std::unique_ptr<engine::TileMap>(map));
}

void KillerKitty::Shutdown() {
    Game::Shutdown();
}

void KillerKitty::Update() {
    Game::Update();

    root.getChildByName("Tiles")->transform.scale = {widow.width / 640.f,
                                                     widow.width / 640.f,
                                                     widow.width / 640.f};
}
