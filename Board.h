#include <vector>
#include <string>
#include <curses.h>
#include <iostream>
#include "Rect.h"

#ifndef CS225_GROUP_PROJECT_BOARD_H
#define CS225_GROUP_PROJECT_BOARD_H

/*
 * Class: Board
 * Description: Base class for games using curses library. Handles displaying game objects and screen management.
 * Member Variables:
 *      int height: height of the board area.
 *      int width: width of the board area.
 *      std::vector<std::shared_ptr<Object>> objects: vector of pointers to game objects.
 * Member Functions: See Prototypes.
 */
class Board {
protected:
    int height;
    int width;
    std::vector<std::unique_ptr<Object>> objects;
public:
    /*
     * Member Function: Board(int w, int h)
     * Description: Class Constructor. Initialize curses settings and stores the height and width of board area.
     * Inputs:
     *      int w: Width of the board area.
     *      int h: Height of the board area.
     * Returns: None.
     */
    Board(int w = 10, int h = 10);

    /*
     * Member Function: print()
     * Description: Prints board objects to curses screen.
     * Inputs: None.
     * Returns: None.
     */
    void print();

    /*
     * Friend Function:  operator<<(std::ostream&, const Board&)
     * Description: Overloaded ostream operator.
     * Inputs:
     *      std::ostream& os: reference of ostream to be added to.
     *      const Board& board: reference of board to be added to ostream.
     * Returns:
     *      std::ostream& os: reference to modified ostream.
     */
    friend std::ostream& operator<<(std::ostream&, const Board&);
};


#endif //CS225_GROUP_PROJECT_BOARD_H
