//
// Created by Severin on 28.02.2023.
//

#include "KillerKitty.h"

#include "InputListener.h"
#include <engine/Entities/SlideShow.h>

void KillerKitty::Setup() {
    Game::Setup();

    root.addEntity(std::make_unique<InputListener>("Exit", *this, &root));
    textureHolder.Load("assets/Tileset/Sheets/Background.png", "Background");

    textureHolder.Load("assets/Tileset/Objects/Leaf/1.png", "1");
    textureHolder.Load("assets/Tileset/Objects/Leaf/2.png", "2");
    textureHolder.Load("assets/Tileset/Objects/Leaf/3.png", "3");
    textureHolder.Load("assets/Tileset/Objects/Leaf/4.png", "4");
    textureHolder.Load("assets/Tileset/Objects/Leaf/5.png", "5");
    textureHolder.Load("assets/Tileset/Objects/Leaf/6.png", "6");

    auto* show = new engine::SlideShow("Leaf", *this, &root, {"1", "2", "3", "4", "5", "6"});
    show->speed = 60;
    show->transform.scale.x = 10;
    show->transform.scale.y = 10;

    root.addEntity(std::unique_ptr<engine::SlideShow>(new engine::SlideShow("Background", *this, &root, {"Background"})));
    root.addEntity(std::unique_ptr<engine::SlideShow>(show));
}

void KillerKitty::Shutdown() {
    Game::Shutdown();

    textureHolder.Unload("Background");
}
