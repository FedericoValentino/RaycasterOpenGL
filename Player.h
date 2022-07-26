//
// Created by valef on 26/07/2022.
//

#ifndef TUTORIALS_PLAYER_H
#define TUTORIALS_PLAYER_H


class Player {
public:
    Player();
    float getX();
    float getY();
    float getOrientation();
    void move();
private:
    float x;
    float y;
    float orientation;



};


#endif //TUTORIALS_PLAYER_H
