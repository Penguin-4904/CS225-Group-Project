#include <iostream>
#include <thread>
#include <chrono>
#include <string>
// For Linux/MacOS clear
#include <stdlib.h>

using namespace std;

int stopflag = 0;

/* Function: user_input
 * Purpose:  Get user input and determine if the user input is correct
 * Returns:  Nothing
 * Precondition:  None
 * Postcondition: None
 */
void user_input()
{
    while (true && !stopflag)
    {
        char user_input;
        cin >> user_input;

        if (user_input == 'c')
        {
            cout << "Input detected" << endl;
        }
        else
        {
            cout << "Incorrect input" << endl;
        }
    }
}

/* Function: game_item
 * Purpose:  Print platorms
 * Returns:  Nothing
 * Precondition:  None
 * Postcondition: None
 */
void game_item()
{
    while (true && !stopflag)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "Game Object*********" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));

        // Clears system needs to be updated to be neutral
        system("clear");
    }
}

int main()
{

    // intalize thread
    thread input(user_input);

    // intalize thread
    thread output(game_item);

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