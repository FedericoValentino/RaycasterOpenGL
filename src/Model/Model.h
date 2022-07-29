//
// Created by valef on 29/07/2022.
//

#ifndef TUTORIALS_MODEL_H
#define TUTORIALS_MODEL_H

#include "Player.h"

class Model{
private:
    int map [5][5] = {{1,1,1,1,1},
                      {1,0,0,0,1},
                      {1,0,0,0,1},
                      {1,0,0,0,1},
                      {1,1,1,1,1}};
    Player* player;
public:
    Model();

    void movePlayer(bool move);

    void rotatePlayer(bool rotate);

    Player *getPlayer() const;
};


#endif //TUTORIALS_MODEL_H
