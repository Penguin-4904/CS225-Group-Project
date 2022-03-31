//
// Created by Tobias Braun on 3/8/22.
//

#include <vector>
#include <string>
#include <curses.h>
#include "Rect.h"

#ifndef CS225_GROUP_PROJECT_BOARD_H
#define CS225_GROUP_PROJECT_BOARD_H


class Board {
protected:
    int height;
    int width;
    std::vector<std::shared_ptr<Object>> objects;
public:
    Board(int w = 10, int h = 10);
    std::vector<std::shared_ptr<Object>> getObjects(){return objects;}
    void print();
    friend std::ostream& operator<<(std::ostream&, Board&);
};


#endif //CS225_GROUP_PROJECT_BOARD_H
