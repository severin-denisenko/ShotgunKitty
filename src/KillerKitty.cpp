//
// Created by Severin on 28.02.2023.
//

#include "KillerKitty.h"

#include "InputListener.h"
#include <engine/Entities/TileMap.h>

void KillerKitty::Setup() {
    Game::Setup();

    root.addEntity(std::make_unique<InputListener>("Exit", *this, &root));

    textureHolder.Load("assets/Tileset/Sheets/Tiles.png", "Tiles");

    auto* map = new engine::TileMap("Tiles", *this, &root, "Tiles");
    int x = 13;
    int y = 8;
    map->Resize(x, y);
    map->Splice(x, y);
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            (*map)(i, j) = i + j * x;
        }
    }

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
