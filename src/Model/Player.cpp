//
// Created by valef on 29/07/2022.
//

#include "Player.h"
#include <cmath>

#define MOVEMENT_AMOUNT 100
#define PI 3.14159

Player::Player() {
    posX = 80;
    posY = 80;
    orientation = 0;
}

void Player::move(bool forward){
    if(forward) {
        posX += std::cos(orientation) * MOVEMENT_AMOUNT * deltaTime;
        posY -= std::sin(orientation) * MOVEMENT_AMOUNT * deltaTime;
    }
    else
    {
        posX -= std::cos(orientation) * MOVEMENT_AMOUNT * deltaTime;
        posY += std::sin(orientation) * MOVEMENT_AMOUNT * deltaTime;
    }
}

void Player::rotate(bool left){
    if(left)
    {
        orientation+= 2.5 * deltaTime;
    }
    else
    {
        orientation-= 2.5 * deltaTime;
    }

    if(orientation > 2*PI)
    {
        orientation -= 2*PI;
    }
    else if(orientation < 0)
    {
        orientation += 2*PI;
    }
}

double Player::getPosX() const {
    return posX;
}

double Player::getPosY() const {
    return posY;
}

double Player::getOrientation() const {
    return orientation;
}

void Player::setDeltaTime(double deltaTime) {
    Player::deltaTime = deltaTime;
}
