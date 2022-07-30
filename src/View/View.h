//
// Created by valef on 29/07/2022.
//

#ifndef TUTORIALS_VIEW_H
#define TUTORIALS_VIEW_H


#include "../Controller/Controller.h"

#include<GL/glew.h>
#include<GLFW/glfw3.h>

class View {
public:
    Controller* gameController;
    GLFWwindow* window;

    double lastFrameTime;
    double currentFrameTime;

    View();
    void initGLFW();
    void mainLoop();
private:
    void keyBoardInput() const;
    void draw();
    void drawMap() const;
    void drawPlayer() const;
    void draw3D();


};


#endif //TUTORIALS_VIEW_H
