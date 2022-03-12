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
    std::vector<std::shared_ptr<Object>> objects;
public:
    Board(int w = 10, int h = 10): height{h}, width{w}{}
    std::vector<std::shared_ptr<Object>> getObjects(){return objects;}
    void addObject(std::shared_ptr<Object>);
    friend std::ostream& operator<<(std::ostream&, const Board&);
};


#endif //CS225_GROUP_PROJECT_BOARD_H
