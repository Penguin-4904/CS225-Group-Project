//
// Created by Tobias Braun on 3/11/22.
//

#include <thread>
#include <chrono>
#include <cmath>

#include <fstream>
#include <ctime>
#include "Board.h"

#ifndef CS225_GROUP_PROJECT_STACK_H
#define CS225_GROUP_PROJECT_STACK_H


class Stack: public Board {
private:

    int rect_height;
    int rect_width;
    int layer;

    bool direction;
    bool gameOver;
    bool inFlag;

    std::thread gameThread;
    std::thread inThread;

    bool step();
    void display();
    void gameThreadFun();
    void inThreadFun();

public:
    Stack(int = 3, int = 1);
    ~Stack();
};


#endif //CS225_GROUP_PROJECT_STACK_H
