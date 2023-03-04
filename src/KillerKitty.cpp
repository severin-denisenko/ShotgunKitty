//
// Created by Severin on 28.02.2023.
//

#include "KillerKitty.h"

#include "InputListener.h"
#include <engine/Entities/TileMap.h>

void KillerKitty::Setup() {
    Game::Setup();

    audioHolder.Load("assets/audio.wav", "audio");
    audioHolder.Play("audio");

    root.addEntity(std::make_unique<InputListener>("Exit", *this, &root));

    textureHolder.Load("assets/Tiles/Tiles.png", "Tiles");
    auto* map = new engine::TileMap("Tiles", *this, &root, "Tiles");
    map->Splice(4, 4);
    map->Load("assets/Tiles/Tilemap.tilemap");

    textureHolder.Load("assets/Tiles/Tiles2.png", "Tiles2");
    auto* map2 = new engine::TileMap("Tiles2", *this, &root, "Tiles2");
    map2->Splice(4, 4);
    map2->Load("assets/Tiles/Tilemap2.tilemap");

    root.addEntity(std::unique_ptr<engine::TileMap>(map2));
    root.addEntity(std::unique_ptr<engine::TileMap>(map));
}

void KillerKitty::Shutdown() {
    Game::Shutdown();
}

void KillerKitty::Update() {
    Game::Update();

    root.transform.scale = {widow.height / 200.f,
                            widow.height / 200.f,
                            widow.height / 200.f};
}
