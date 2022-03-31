//
// Created by Tobias Braun on 3/11/22.
//

#include "Stack.h"

Stack::Stack(int size) : Board(20, 20), direction{1}, squareSize{size}, layer{2}, rect_width{size}, gameOver(false), inFlag(false) {
    objects.push_back(std::make_shared<Rect>(Rect(squareSize, squareSize, (width - squareSize)/2, height - squareSize)));
    objects.push_back(std::make_shared<Rect>(Rect(squareSize, squareSize, 0, height - layer * squareSize)));
    inThread = std::thread(&Stack::inThreadFun, this);
    gameThread = std::thread(&Stack::gameThreadFun, this);
}

bool Stack::step() {

    int x_block = objects.back()->posX();
    int x_tower = objects.end()[-2]->posX();
    if (inFlag) {
        inFlag = false;
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


    return false;

}

void Stack::display() {
    clear();
    if (!gameOver){
        this->print();
        move(0, 0);
        std::string score = "Score: " + std::to_string(layer - 2);
        addstr(score.c_str());
    } else {
        std::string text = "Game Over!";
        move(height/2, (width/2.0 - text.length()/2.0));
        addstr("Game Over!");
        std::string score = "Score: " + std::to_string(layer - 2);
        move(height/2 + 1, (width/2.0 - score.length()/2.0));
        addstr(score.c_str());
        move(0,0);
    }
    refresh();
}

void Stack::gameThreadFun() {

    while (!gameOver){

        if (!gameOver){
            gameOver = this->step();
        }

        this->display();

        std::this_thread::sleep_for(std::chrono::milliseconds(int(1000 * exp(1-layer))));

    }
}

void Stack::inThreadFun() {

    while (!gameOver){

        std::cin.ignore();
        inFlag = true;

    }
}

Stack::~Stack() {
    inThread.join();
    gameThread.join();
}



