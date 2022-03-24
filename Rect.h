//
// Created by Tobias Braun on 3/8/22.
//

#include "Object.h"
#include <string>
#include <vector>

#ifndef CS225_GROUP_PROJECT_RECT_H
#define CS225_GROUP_PROJECT_RECT_H


class Rect : public Object {
private:
    int height;
    int width;
public:
    Rect(int w = 2, int h = 2, int x_i = 0, int y_i = 0): Object(x_i, y_i), height{h}, width{w} {}
    std::vector<std::string> print() const;
};


#endif //CS225_GROUP_PROJECT_RECT_H
