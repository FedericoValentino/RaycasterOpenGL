//
// Created by valef on 29/07/2022.
//

#include "View.h"

#include<GL/glew.h>
#include<GLFW/glfw3.h>


#include<cmath>


#define HEIGHT 320
#define WIDTH 640

#define CELLSIZE 40

View::View() {
    gameController = new Controller();
    window = nullptr;
    initGLFW();
}

void View::initGLFW() {
    glfwInit();

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    window = glfwCreateWindow(WIDTH, HEIGHT, "Raycast", nullptr, nullptr);

    glfwMakeContextCurrent(window);
    glewExperimental = true;
    glewInit();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, WIDTH, HEIGHT, 0.0f, 0.0f, 1.0f);
}

void View::keyBoardInput() const {

    if (glfwGetKey( window, GLFW_KEY_UP ) == GLFW_PRESS){
        gameController->move(true);
    }
    if (glfwGetKey( window, GLFW_KEY_DOWN ) == GLFW_PRESS){
        gameController->move(false);
    }
    if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
        gameController->rotate(false);
    }
    if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS){
        gameController->rotate(true);
    }
}

void View::mainLoop() {
    while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0)
    {
        draw();
        keyBoardInput();
    }
}

void View::draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    currentFrameTime = glfwGetTime();
    gameController->getModel()->setDeltaTime(currentFrameTime - lastFrameTime);
    lastFrameTime = currentFrameTime;
    gameController->getModel()->castRays();

    drawMap();
    drawPlayer();
    draw3D();


    glfwSwapBuffers(window);
    glfwPollEvents();
}

void View::drawMap() const {
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j< 8; j++)
        {
            if(gameController->getModel()->getMap(i,j) == 1)
            {
                glColor3f(1,1,1);
            }
            else
            {
                glColor3f(0,0,0);
            }
            int x0 = j * CELLSIZE;
            int y0 = i * CELLSIZE;

            glBegin(GL_QUADS);
            glVertex2i(x0 + CELLSIZE, y0); //topRight
            glVertex2i(x0 + CELLSIZE, y0+CELLSIZE); //bottomRight
            glVertex2i(x0, y0 + CELLSIZE); //topLeft
            glVertex2i(x0, y0); //bottomLeft
            glEnd();
        }
    }
}

void View::drawPlayer() const {
    double x = gameController->getModel()->getPlayer()->getPosX();
    double y = gameController->getModel()->getPlayer()->getPosY();
    double dx = std::cos(gameController->getModel()->getPlayer()->getOrientation()) * 10;
    double dy = -std::sin(gameController->getModel()->getPlayer()->getOrientation()) * 10;



    glColor3f(1,1,0);

    glBegin(GL_LINES);
    glVertex2i(x, y);
    glVertex2i(x + dx, y+ dy);
    glEnd();

    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();


    for(std::vector<double> hit : gameController->getModel()->getHits())
    {
        glLineWidth(2);
        glColor3f(0,0,1);
        glBegin(GL_LINES);
        glVertex2i(x, y);
        glVertex2i(hit[0], hit[1]);
        glEnd();
    }


}

void View::draw3D()
{
    int x0 = 325;
    int y0 = 280;


    for(std::vector<double> hit : gameController->getModel()->getHits())
    {
        double wallDistance = hit[2] + 0.001;
        double PWallHeight = (CELLSIZE / wallDistance) * 200;
        if(PWallHeight > 320)
        {
            PWallHeight = 320;
        }
        int lineOff = 160 - ((int)PWallHeight >>1);
        glColor3f(1,1,1);
        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2i(x0,lineOff);
        glVertex2i(x0,lineOff+PWallHeight);
        glEnd();

        glEnd();
        x0 += 1;
    }


}
