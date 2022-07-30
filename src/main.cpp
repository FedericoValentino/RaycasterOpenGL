#include<stdio.h>
#include<stdlib.h>

#include "View/View.h"

int main()
{
    View* currentView = new View();
    currentView->mainLoop();
}