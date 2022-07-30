//
// Created by valef on 29/07/2022.
//

#include <cstdlib>
#include <cmath>
#include <cstdio>
#include "Model.h"

#define PI 3.14159

#define MAPSIZE 8

#define CELLSIZE 40


Model::Model() {
   player = new Player();
}

void Model::movePlayer(bool move) {
    player->move(move);
}

void Model::rotatePlayer(bool rotate) {
    player->rotate(rotate);
}

Player *Model::getPlayer() const {
    return player;
}


int Model::getMap(int x, int y) {
    return map[x][y];
}

void Model::setDeltaTime(double deltaTime) {
    player->setDeltaTime(deltaTime);
}

const std::list<std::vector<double>> &Model::getHits() const {
    return hits;
}

void Model::castRays() {

    int dof;
    double rayStartingAngle = player->getOrientation() - 30*PI/180;
    double pY = player->getPosY();
    double pX = player->getPosX();
    double rayY;
    double rayX;
    double offsetY;
    double offsetX;

    int mapX;
    int mapY;

    std::vector<double> hitH;
    std::vector<double> hitV;

    hits.clear();

    for(int ray = 0; ray < 320; ray++)
    {
        //vertical line
        double distV = 10000;
        double distH = 10000;
        dof = 0;
        if(std::cos(rayStartingAngle) < 0) //Looking left
        {
            rayX = (((int)pX / CELLSIZE) * CELLSIZE) - 0.001;
            rayY = pY + (pX-rayX)*std::tan(rayStartingAngle);
            offsetX = -CELLSIZE;
            offsetY = -offsetX * std::tan(rayStartingAngle);
        }
        else if(std::cos(rayStartingAngle) > 0) // Looking right
        {
            rayX = (((int)pX / CELLSIZE) * CELLSIZE) + CELLSIZE;
            rayY = pY + (pX-rayX)*std::tan(rayStartingAngle);
            offsetX = +CELLSIZE;
            offsetY = -offsetX * std::tan(rayStartingAngle);
        }
        else
        {
            rayX = pX;
            rayY = pY;
            dof = MAPSIZE;
        }


        while(dof < MAPSIZE)
        {
            mapX = rayX/CELLSIZE;
            mapY = rayY/CELLSIZE;

            if(mapX >= 0 && mapX < MAPSIZE && mapY >= 0 && mapY < MAPSIZE && map[mapY][mapX] != 0)
            {
                dof = MAPSIZE;
                double currentAngle = FixAngle(player->getOrientation() - rayStartingAngle);

                distV = std::sqrt(std::pow((rayX-pX), 2) + std::pow((rayX-pX), 2)) * std::cos(currentAngle);
                hitV = {rayX, rayY, distV};
            }
            else
            {
                rayX += offsetX;
                rayY += offsetY;
                dof++;
            }
        }



        //Horizontal lines
        dof = 0;
        if(std::sin(rayStartingAngle) < 0) //Looking down
        {
            rayY = (((int)pY / CELLSIZE) * CELLSIZE) + CELLSIZE;
            rayX = pX + (pY-rayY)/std::tan(rayStartingAngle);
            offsetY = CELLSIZE;
            offsetX = -offsetY / std::tan(rayStartingAngle);

        }
        else if(std::sin(rayStartingAngle) > 0) // Looking up
        {
            rayY = (((int)pY / CELLSIZE) * CELLSIZE) -1;
            rayX = pX + (pY-rayY)/std::tan(rayStartingAngle);
            offsetY = -CELLSIZE;
            offsetX = -offsetY / std::tan(rayStartingAngle);

        }
        else
        {
            rayX = pX;
            rayY = pY;
            dof = MAPSIZE;
        }


        while(dof < MAPSIZE)
        {
            mapX = rayX/CELLSIZE;
            mapY = rayY/CELLSIZE;

            if(mapX >= 0 && mapX < MAPSIZE && mapY >= 0 && mapY < MAPSIZE && map[mapY][mapX] != 0)
            {
                dof = MAPSIZE;
                double currentAngle = FixAngle(player->getOrientation() - rayStartingAngle);

                distH = std::sqrt(std::pow((rayX-pX), 2) + std::pow((rayX-pX), 2)) * std::cos(currentAngle);
                hitH = {rayX, rayY, distH};
            }
            else
            {
                rayX += offsetX;
                rayY += offsetY;
                dof++;
            }
        }

        if(distH < distV)
        {
            hits.push_front(hitH);
        }
        else
        {
            hits.push_front(hitV);
        }

        rayStartingAngle += 0.00327;
    }

}

double Model::FixAngle(double orientation) {
    if(orientation > 2*PI)
    {
        orientation -= 2*PI;
    }
    else if(orientation < 0)
    {
        orientation += 2*PI;
    }

    return orientation;
}
