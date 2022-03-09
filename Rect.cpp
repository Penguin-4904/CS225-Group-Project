//
// Created by Tobias Braun on 3/8/22.
//

#include "Rect.h"

std::string* Rect::print(){
    std::string * out;
    out = new std::string[sizeY];
    for (int i = 0; i < sizeY; i++){
        out[i] = std::string(sizeX, '#');
    }
    return out;
}