//
// Created by valef on 29/07/2022.
//

#ifndef TUTORIALS_PLAYER_H
#define TUTORIALS_PLAYER_H


class Player {
private:
    int posX;
    int posY;
    double orientation;
public:
    Player();
    void move(bool forward);
    void rotate(bool left);

    int getPosX() const;
    int getPosY() const;
    double getOrientation() const;
};


#endif //TUTORIALS_PLAYER_H
