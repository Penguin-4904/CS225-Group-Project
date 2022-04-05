#include "Object.h"
#include <string>
#include <vector>

#ifndef CS225_GROUP_PROJECT_RECT_H
#define CS225_GROUP_PROJECT_RECT_H

/*
 * Class: Rect
 * Description: Rectangle class that inherits from the object class and is a rectangular shape.
 * Member Variables:
 *      int height: Height of the rectangle.
 *      int width: Width of the rectangle.
 * Member Functions: See Prototypes.
 */
class Rect : public Object {
private:
    int height;
    int width;
public:
    /*
     * Member Function: Rect()
     * Description: Class Constructor. Sets the rectangle size and position.
     * Inputs:
     *      int w: rectangle width.
     *      int h: rectangle height.
     *      int x_i: rectangle x position.
     *      int y_i: rectangle y position.
     * Returns: None.
     */
    Rect(int w = 2, int h = 2, int x_i = 0, int y_i = 0): Object(x_i, y_i), height{h}, width{w} {}

    /*
     * Member Function: print()
     * Description: Returns a vector of strings that are the y layers of the rectangle to be printed.
     * Input: None.
     * Returns:
     *      std::vector<std::string> out: a vector of strings, each of which is a different y layer that iw to be printed to the screen.
     */
    std::vector<std::string> print() const;
};


#endif //CS225_GROUP_PROJECT_RECT_H
