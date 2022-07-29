//
// Created by valef on 29/07/2022.
//

#include "Player.h"
#include <cmath>

#define MOVEMENT_AMOUNT 5
#define PI 3.14159

Player::Player() {
    posX = 0;
    posY = 0;
    orientation = PI/2;
}

void Player::move(bool forward){
    if(forward) {
        posX += std::cos(orientation) * 5;
        posY += std::sin(orientation) * 5;
    }
    else
    {
        posX -= std::cos(orientation) * 5;
        posY -= std::sin(orientation) * 5;
    }
}

void Player::rotate(bool left){
    if(left)
    {
        orientation+= 0.017;
    }
    else
    {
        orientation+= 0.017;
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

int Player::getPosX() const {
    return posX;
}

int Player::getPosY() const {
    return posY;
}

double Player::getOrientation() const {
    return orientation;
}
