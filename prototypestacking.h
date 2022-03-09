// This is a temporary file to test the capabilities of stacking
// Code written in this file will have to be sepearated and worked on

// Header
#include <iostream> 
#include <stdio.h> 

// namespace
using namespace std;

// Stacking Class
class StackAndPlay{
    private:
        int roundMax;
        int arraySize;
    public:
        // Set up terminal to allow for a key to be pressed and registered without hitting space
        StackAndPlay(){system("stty raw");};
        // Reset the terminal to its original state
        ~StackAndPlay(){system("stty cooked");};
        void setRoundAmount(int roundInput = 10){ roundMax = roundInput};
        void playRound(){
            int currentRound = 1;
            do while (currentRound <= roundMax){

                // Print Base Platform
                cout << stack[1];
                // Print "moving" platform
                    

                // Delay of x per movment to allow user to see

                // Accept User Input
                char input = getchar(); 

                if(input == " "){
                    // Need to implement how to stop the platform
                }

                // Clear Screen
                // Specific To MacOS
                system("clear)";
                
                currentRound++;
            }
        };
        void setArraySize(int desiredArraySize = 15){arraySize = desiredArraySize};
        void movingPlatform(){};
};


// I feel like the following needs to be done in main or somewhere else

// intalize Array
Stack *stack[size];

// Intalize starting platform
stack[1]->"▢▢▢▢▢";





