//
// Created by Tobias Braun on 3/8/22.
//

#include "Rect.h"
#include <vector>
#include <string>
#include <iostream>
#include <curses.h>

#ifndef CS225_GROUP_PROJECT_BOARD_H
#define CS225_GROUP_PROJECT_BOARD_H


class Board {
protected:
    int height;
    int width;
    WINDOW * win;
    std::vector<std::shared_ptr<Object>> objects;
public:
    Board(int w = 10, int h = 10);
    std::vector<std::shared_ptr<Object>> getObjects(){return objects;}
    void addObject(std::shared_ptr<Object>);
    void print();
};


#endif //CS225_GROUP_PROJECT_BOARD_H
