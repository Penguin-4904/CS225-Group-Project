//
// Created by Tobias Braun on 3/3/22.
//

// Libraries
#include <iostream>
#include <string>

#include "Board.h"

// Reference Files

// Namespace
using namespace std;


// Main
int main(){
    Board stack;
    Rect test(2, 2, 9, 8);
    stack.addObject(&test);
    cout<<stack<<endl;
    return 0;
}

