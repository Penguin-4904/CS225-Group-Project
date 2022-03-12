//
// Created by Tobias Braun on 3/8/22.
//

#include <string>

#ifndef CS225_GROUP_PROJECT_OBJECT_H
#define CS225_GROUP_PROJECT_OBJECT_H


class Object {
protected:
    int x;
    int y;
public:
    Object(int x_i = 0, int y_i = 0): x{x_i}, y{y_i} {}
    virtual std::vector<std::string> print() const = 0;
    int posX() const {return x;}
    int posY() const {return y;}
    void setX(int X) {x = X;}
    void setY(int Y) {y = Y;}
};


#endif //CS225_GROUP_PROJECT_OBJECT_H
