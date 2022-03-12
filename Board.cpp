//
// Created by Tobias Braun on 3/8/22.
//

#include "Board.h"

void Board::addObject(std::shared_ptr<Object> obj) {
    objects.push_back(obj);
}

std::ostream& operator<<(std::ostream& out, const Board& board) {

    std::string line(board.width, '*');
    line += "\n";

    std::string boardString;
    for (int i = 0; i < board.height; i++){
        boardString += line;
    }

    int n = board.objects.size();

    for (int i = 0; i < n; i++){
        std::vector<std::string> v = board.objects[i]->print();
        int y = board.objects[i]->posY();
        int x = board.objects[i]->posX();
        for (int j = 0; j < v.size() && (j + y) < board.height; j++){
            boardString.replace((y + j) * line.length() + x, std::min((int)v[j].length(), board.width - x), v[j], 0, board.width - x);
        }
    }

    out << boardString;

    return out;
}