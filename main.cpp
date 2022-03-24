
#include <iostream>
#include <thread>
#include <chrono>
#include "Stack.h"
#include <string>
// For Linux/MacOS clear
#include <stdlib.h>

using namespace std;

/* Function: user_input
 * Purpose:  Get user input and determine if the user input is correct
 * Returns:  Nothing
 * Precondition:  None
 * Postcondition: None
 */
void user_input(bool* stop_flag, bool* flag)
{
    while (!*stop_flag)
    {
        cin.ignore();
        *flag = true;
    }
}

/* Function: game_item
 * Purpose:  Print platorms
 * Returns:  Nothing
 * Precondition:  None
 * Postcondition: None
 */
void game_item(bool* stop_flag, Stack* st, bool* in_flag)
{
    while (!*stop_flag)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        *stop_flag = st->step(*in_flag);
        *in_flag = false;
    }
}

int main()
{
    cout << "Start";

    Stack stack;

    bool input_flag = false;
    bool stop_flag = false;

    // intalize thread
    thread input(user_input, &stop_flag, &input_flag);

    // intalize thread
    thread output(game_item, &stop_flag, &stack, &input_flag);

    // join the threads to wait for each other
    input.join();
    output.join();

    // end threads
    input.~thread();
    output.~thread();

    cout << "end" << endl;

    // Return
    return 0;
}

