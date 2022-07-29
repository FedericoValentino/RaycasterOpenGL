//
// Created by valef on 29/07/2022.
//

#ifndef TUTORIALS_CONTROLLER_H
#define TUTORIALS_CONTROLLER_H


#include "../Model/Model.h"

class Controller {
private:
    Model model;
public:
    void move(bool forward);
    void rotate(bool left);


    bool checkWallCollision();
};


#endif //TUTORIALS_CONTROLLER_H