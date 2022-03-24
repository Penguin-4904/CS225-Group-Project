//
// Created by Tobias Braun on 3/3/22.
//

// Libraries
#include <iostream>
#include <unistd.h>
#include "Stack.h"

// Reference Files

// Namespace
using namespace std;


// Main
int main(){
    int maxH, maxW;
    getmaxyx(stdscr, maxH, maxW);
    cout << maxH << endl;
    cout << maxW << endl;
    Stack stack;
    int count = 0;
    while (count < 60){
        count ++;
        usleep(100000);
        stack.step();
        // what
    }
    return 0;
}

