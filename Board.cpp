//
// Created by Tobias Braun on 3/8/22.
//

#include "Board.h"

Board::Board(int w, int h) {
    initscr();
    cbreak();
    noecho();
    int maxH, maxW;
    getmaxyx(stdscr, maxH, maxW);
    height = h;
    width = w;
}

void Board::addObject(std::shared_ptr<Object> obj) {
    objects.push_back(obj);
}

void Board::print() {
    clear();
    int n = objects.size();

    for (int i = 0; i < n; i++){
        std::vector<std::string> v = objects[i]->print();
        int y = objects[i]->posY();
        int x = objects[i]->posX();
        for (std::string s : v) {
            move(y, x);
            y++;
            addstr(s.c_str());
        }
    }
    refresh();
}


