//
// Created by valef on 29/07/2022.
//

#include <cstdlib>
#include "Model.h"


Model::Model() {
   player = new Player();
}

void Model::movePlayer(bool move) {
    player->move(move);
}

void Model::rotatePlayer(bool rotate) {
    player->rotate(rotate);
}

Player *Model::getPlayer() const {
    return player;
}
