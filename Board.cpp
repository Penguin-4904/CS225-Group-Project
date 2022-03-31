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

std::ostream& operator<<(std::ostream& os, const Board& board) {

    std::string boardString;

    for (int i = 0; i < board.height; i++){
        boardString += std::string(board.width, ' ') += "\n" ;
    }

    int n = board.objects.size();

    for (int i = 0; i < n; i++){
        std::vector<std::string> v = board.objects[i]->print();
        int y = board.objects[i]->posY();
        int x = board.objects[i]->posX();
        for (int j = 0; j < v.size() && (j + y) < board.height; j++){
            boardString.replace((y + j) * (board.width + 1) + x, std::min((int)v[j].length(), board.width - x), v[j], 0, board.width - x);
        }
    }

    os << boardString;

    return os;
}


