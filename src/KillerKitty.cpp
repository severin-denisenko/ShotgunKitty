//
// Created by Severin on 28.02.2023.
//

#include "KillerKitty.h"

#include "InputListener.h"
#include <engine/Entities/TileMap.h>

void KillerKitty::Setup() {
    Game::Setup();

    root.addEntity(std::make_unique<InputListener>("Exit", *this, &root));

    textureHolder.Load("assets/Tileset/Tiles/Tile_01.png", "1");
    textureHolder.Load("assets/Tileset/Tiles/Tile_02.png", "2");
    textureHolder.Load("assets/Tileset/Tiles/Tile_03.png", "3");
    textureHolder.Load("assets/Tileset/Tiles/Tile_05.png", "4");
    textureHolder.Load("assets/Tileset/Tiles/Tile_06.png", "5");
    textureHolder.Load("assets/Tileset/Tiles/Tile_07.png", "6");

    auto* map = new engine::TileMap("Tiles", *this, &root, {"1", "2", "3", "4", "5", "6"});
    map->Resize(3, 2);
    (*map)(0, 0) = 0;
    (*map)(1, 0) = 1;
    (*map)(2, 0) = 2;
    (*map)(0, 1) = 3;
    (*map)(1, 1) = 4;
    (*map)(2, 1) = 5;

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
