//
// Created by Tobias Braun on 3/11/22.
//

#include "Stack.h"

Stack::Stack(int size) : Board(20, 20), direction{1}, squareSize{size}, layer{2}, rect_width{size} {
    addObject(std::make_shared<Rect>(Rect(squareSize, squareSize, (width - squareSize)/2, height - squareSize)));
    addObject(std::make_shared<Rect>(Rect(squareSize, squareSize, 0, height - layer * squareSize)));
}

bool Stack::step(bool in) {
    int x_block = objects.back()->posX();
    int x_tower = objects.end()[-2]->posX();
    if (in) {
        rect_width -= abs(x_block - x_tower);
        if (rect_width <= 0){
            return true;
        }
        objects.pop_back();
        objects.push_back(std::make_shared<Rect>(Rect(rect_width, squareSize, std::max(x_block, x_tower), height - layer * squareSize)));
        layer++;
        objects.push_back(std::make_shared<Rect>(Rect(rect_width, squareSize, 0, height - layer * squareSize)));
    }

    else{
        if (x_block + squareSize >= width){
            direction = -1;
        }
        if (x_block <= 0){
            direction = 1;
        }
        objects.back()->setX(x_block + direction);
    }

    this->print();
    return false;
}
