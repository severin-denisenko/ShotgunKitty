//
// Created by Severin on 28.02.2023.
//

#ifndef SHOTGUNKITTY_KILLERKITTY_H
#define SHOTGUNKITTY_KILLERKITTY_H

#include <engine/Game.h>

class KillerKitty : public engine::Game {
public:
    KillerKitty() : Game("KillerKitty") {}

    void Setup() override;
    void Shutdown() override;
};


#endif //SHOTGUNKITTY_KILLERKITTY_H
