#include "Player.h"
#include <cmath>

#define PI 3.14159

Player::Player()
{
    x = 0;
    y = 0;
    orientation = PI/2;
}


float Player::getX() {
    return x;
}

float Player::getY() {
    return y;
}

float Player::getOrientation() {
    return orientation;
}

void Player::move()
{
    x += std::cos(orientation);
    y += std::sin(orientation);
}
