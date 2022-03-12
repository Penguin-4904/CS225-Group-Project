//
// Created by Tobias Braun on 3/8/22.
//

#include "Rect.h"
#include <vector>
#include <string>
#include <iostream>

#ifndef CS225_GROUP_PROJECT_BOARD_H
#define CS225_GROUP_PROJECT_BOARD_H


class Board {
protected:
    int height;
    int width;
    std::vector<Object*> objects;
public:
    Board(int h = 10, int w = 10): height{h}, width{w}{}
    std::vector<Object*> getObjects(){return objects;}
    void addObject(Object*);
    friend std::ostream& operator<<(std::ostream&, const Board&);
};


#endif //CS225_GROUP_PROJECT_BOARD_H
