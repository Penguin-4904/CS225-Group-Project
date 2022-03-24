//
// Created by Tobias Braun on 3/11/22.
//

#include "Stack.h"

Stack::Stack(int size) : Board(20, 20), direction{1}, squareSize{size}, layer{2} {
    addObject(std::make_shared<Rect>(Rect(squareSize, squareSize, (width - squareSize)/2, height - squareSize)));
    addObject(std::make_shared<Rect>(Rect(squareSize, squareSize, 0, height - layer * squareSize)));
}

void Stack::step() {
    int x = objects.back()->posX();
    if (x + squareSize >= width){
        direction = -1;
    }
    if (x <= 0){
        direction = 1;
    }

    objects.back()->setX(x + direction);

    this->print();
}
