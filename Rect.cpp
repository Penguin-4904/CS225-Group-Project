//
// Created by Tobias Braun on 3/8/22.
//

#include "Rect.h"

std::vector<std::string> Rect::print() const {
    std::vector<std::string> out;
    std::string line = std::string(width, '#');
    for (int i = 0; i < height; i++){
        out.push_back(line);
    }
    return out;
}