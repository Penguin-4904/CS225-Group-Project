//
// Created by Tobias Braun on 3/3/22.
//

// Libraries
#include <iostream>
#include <string>
#include <unistd.h>
#include <curses.h>
#include "Stack.h"

// Reference Files

// Namespace
using namespace std;


// Main
int main(){
    Stack stack;
    int count = 0;
    while (count < 60){
        count ++;
        usleep(10000);
        stack.step();
    }
    return 0;
}

