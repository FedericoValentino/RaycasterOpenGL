//
// Created by valef on 29/07/2022.
//

#include "Controller.h"
#include <cmath>

#define PLAYER_RAD 20;

void Controller::move(bool forward) {
    if(!checkWallCollision())
    {
        model->movePlayer(forward);
    }
}

void Controller::rotate(bool left) {
    model->rotatePlayer(left);
}

bool Controller::checkWallCollision() {
    return false;
}

Controller::Controller() {
    model = new Model();

}

Model *Controller::getModel() const {
    return model;
}
