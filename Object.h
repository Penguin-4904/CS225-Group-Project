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
    virtual std::string* print();
    int posX() {return x}
    int posY() {return y}
};


#endif //CS225_GROUP_PROJECT_OBJECT_H
