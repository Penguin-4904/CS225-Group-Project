#include <thread>
#include <chrono>
#include <cmath>

#include <fstream>
#include <ctime>
#include "Board.h"

#ifndef CS225_GROUP_PROJECT_STACK_H
#define CS225_GROUP_PROJECT_STACK_H


/*
 * Class: Stack
 * Description: This class manages and runs a stacking game instance simply by existing. The constructor starts the game and the destructor waits for it to finish.
 * Member Variables:
 *      int rect_height: The height of the stacking blocks.
 *      int rect_width: The width of the stacking blocks.
 *      int layer: The current stacking layer that the game is on. Is used to determine score and moving block position.
 *      bool direction: The direction that the current moving block is moving in. true = +x, false = -x.
 *      bool gameOver: False = game is still running, True = Game has been lost.
 *      bool inFlag: Flag raised by the input thread when any input is detected.
 * Member Functions: See Prototypes.
 */
class Stack: public Board {
private:

    int rect_height;
    int rect_width;
    int layer;

    bool direction;
    bool gameOver;
    bool inFlag;

    std::thread gameThread;
    std::thread inputThread;

    /*
     * Member Function: step()
     * Description: Progresses the game state by one frame.
     * Inputs: None.
     * Returns: None.
     */
    bool step();

    /*
     * Member Function: display()
     * Description: Prints and Blits the current game state to the screen.
     * Inputs: None.
     * Returns: None.
     */
    void display();

    /*
     * Member Function: game_thread_fun()
     * Description: The function run by the game thread. Used to progress the game and time frame steps.
     * Inputs: None.
     * Returns: None.
     */
    void game_thread_fun();

    /*
     * Member Function: input_thread_fun()
     * Description: The function run by the input thread. Raises the inFlag whenever a keyboard input is detected.
     * Inputs: None.
     * Returns: None.
     */
    void input_thread_fun();

public:

    /*
     * Member Function: Stack(int rw, int rh)
     * Description: Class Constructor. Creates the initial game Objects and sets initial values.
     * Inputs:
     *      int rw: The initial rectangle width.
     *      int rh: The rectangle height.
     * Returns: None
     */
    Stack(int = 3, int = 1);

    /*
     * Member Function: ~Stack()
     * Description: Class Destructor. Waits for the game thread and input thread to finish. Prints last game state to file.
     * Inputs: None.
     * Returns: None.
     */
    ~Stack();
};


#endif //CS225_GROUP_PROJECT_STACK_H
