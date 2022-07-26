#include<stdio.h>
#include<stdlib.h>
#include<cmath>

#include<GL/glew.h>
#include<GLFW/glfw3.h>


#include "Player.h"

#define WIDTH 1024
#define HEIGHT 768

#define R 20.0

GLFWwindow* window;

Player* p1 = new Player();



GLFWwindow* initialization()
{
    glfwInit();

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    return glfwCreateWindow(WIDTH, HEIGHT, "Raycast", nullptr, nullptr);
}

void drawLoop()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(p1->getX()/WIDTH, p1->getY()/HEIGHT);
    glVertex2f((p1->getX() + std::cos(p1->getOrientation())*R)/WIDTH, (p1->getY() + std::sin(p1->getOrientation())*R)/HEIGHT);
    glEnd();

    glPointSize(8);
    glColor3f(1, 1, 0);
    glBegin(GL_POINTS);
    glVertex2d(p1->getX(), p1->getY());
    glEnd();



    glfwSwapBuffers(window);
    glfwPollEvents();
}


int main()
{
    window = initialization();

    glfwMakeContextCurrent(window);

    glewExperimental = true;

    glewInit();




    float aspect = (float)WIDTH/HEIGHT;
    glOrtho(-aspect, aspect, -1.0f, 1.0f, -1.0f, 1.0f);
    while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0)
    {
        drawLoop();
    }
}