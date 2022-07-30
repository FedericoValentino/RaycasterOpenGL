//
// Created by valef on 29/07/2022.
//

#ifndef TUTORIALS_MODEL_H
#define TUTORIALS_MODEL_H

#include <vector>
#include <list>
#include "Player.h"

class Model{
private:
    int map[8][8]=           //the map array. Edit to change level but keep the outer walls
            {
                    { 1, 1, 1, 1, 1, 1, 1, 1},
                    { 1, 0, 1, 0, 0, 0, 0, 1},
                    { 1, 0, 1, 0, 0, 0, 0, 1},
                    { 1, 0, 1, 0, 0, 0, 0, 1},
                    { 1, 0, 0, 0, 0, 0, 0, 1},
                    { 1, 0, 0, 0, 0, 1, 0, 1},
                    { 1, 0, 0, 0, 0, 0, 0, 1},
                    { 1, 1, 1, 1, 1, 1, 1, 1}
            };
    Player* player;

    std::list<std::vector<double>> hits;

public:
    Model();

    void movePlayer(bool move);

    void rotatePlayer(bool rotate);

    void castRays();

    Player *getPlayer() const;

    int getMap(int x, int y);

    void setDeltaTime(double deltaTime);

    const std::list<std::vector<double>> &getHits() const;

    double FixAngle(double d);
};


#endif //TUTORIALS_MODEL_H
