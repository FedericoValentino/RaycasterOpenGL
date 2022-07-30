//
// Created by valef on 29/07/2022.
//

#ifndef TUTORIALS_PLAYER_H
#define TUTORIALS_PLAYER_H


class Player {
private:
    double posX;
    double posY;
    double orientation;
    double deltaTime;
public:
    Player();
    void move(bool forward);
    void rotate(bool left);

    double getPosX() const;
    double getPosY() const;
    double getOrientation() const;

    void setDeltaTime(double deltaTime);
};


#endif //TUTORIALS_PLAYER_H
