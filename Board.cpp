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

void Board::print() {
    int n = objects.size();

    for (int i = 0; i < n; i++){
        std::vector<std::string> v = objects[i]->print();
        int y = objects[i]->posY();
        int x = objects[i]->posX();
        for (std::string s : v) {
            move(y, x);
            addstr(s.c_str());
            y++;
        }
    }
}

std::ostream &operator<<(std::ostream& os, Board& board) {

    return os;
}


