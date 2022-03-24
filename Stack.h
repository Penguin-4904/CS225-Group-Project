//
// Created by Tobias Braun on 3/11/22.
//

#include "Board.h"

#ifndef CS225_GROUP_PROJECT_STACK_H
#define CS225_GROUP_PROJECT_STACK_H


class Stack: public Board {
private:
    int direction;
    int squareSize;
    int layer;
    int rect_width;
public:
    Stack(int size = 3);
    bool step(bool);

};


#endif //CS225_GROUP_PROJECT_STACK_H
