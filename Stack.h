//
// Created by Tobias Braun on 3/11/22.
//

#include <thread>
#include <chrono>
#include <math.h>
#include <iostream>
#include "Board.h"

#ifndef CS225_GROUP_PROJECT_STACK_H
#define CS225_GROUP_PROJECT_STACK_H


class Stack: public Board {
private:
    int direction;
    int squareSize;
    int layer;
    int rect_width;

    bool gameOver;
    bool inFlag;

    std::thread gameThread;
    std::thread inThread;

    bool step();
    void display();
    void gameThreadFun();
    void inThreadFun();

public:
    Stack(int size = 3);
    ~Stack();
};


#endif //CS225_GROUP_PROJECT_STACK_H
