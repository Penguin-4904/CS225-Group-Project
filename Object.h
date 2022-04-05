#include <string>
#include <vector>

#ifndef CS225_GROUP_PROJECT_OBJECT_H
#define CS225_GROUP_PROJECT_OBJECT_H

/*
 * Virtual Class: Object
 * Description: Virtual object base class used to define needed functions to be used by the Board class
 * Member Variables:
 *      int x: x position of object
 *      int y: y position of object
 * Member Functions: See Prototypes
 */
class Object {
protected:
    int x;
    int y;
public:
    /*
     * Member Function: Object()
     * Description: Class Constructor. Sets starting x and y position of object
     * Input:
     *      int x_i: Starting x position
     *      int y_i: Starting y position
     * Returns: None
     */
    Object(int x_i = 0, int y_i = 0): x{x_i}, y{y_i} {}

    /*
     * Virtual Member Function: print()
     * Description: Function template to be fulfilled by inheriting classes
     * Inputs: None
     * Returns:
     *      std::vector<std::string> v: a vector of strings to be printed
     */
    virtual std::vector<std::string> print() const = 0;

    /*
     * Member Functions: Setter and Getter functions for x position and y position.
     */
    int posX() const {return x;}
    int posY() const {return y;}
    void setX(int X) {x = X;}
    void setY(int Y) {y = Y;}
};


#endif //CS225_GROUP_PROJECT_OBJECT_H
