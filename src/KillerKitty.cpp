//
// Created by Severin on 28.02.2023.
//

#include "KillerKitty.h"

#include "InputListener.h"

void KillerKitty::Setup() {
    Game::Setup();

    root.addEntity(std::make_unique<InputListener>("Exit", *this, &root));
}

void KillerKitty::Shutdown() {
    Game::Shutdown();


}
