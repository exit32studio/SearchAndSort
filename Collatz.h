//
//  Collatz.h
//  SearchAndSort
//
//  Created by Joseph Bobula on 6/30/18.
//  Copyright © 2018 Joseph Bobula. All rights reserved.
//

#ifndef Collatz_h
#define Collatz_h

#include <stdio.h>

//Pass in an unsigned int and the function will tell you how many steps it takes to complete the Collatz conjecture
int collatz(unsigned int n);

//Pass in an array of numbers and return a pointer to an array that counts the number of steps needed to complete the Collatz conjecture for each passed number
//Pass in an array to receive the number of steps as *buffer
void numberOfSteps(int numbersToTest[], int numberOfElements, int *buffer);

#endif /* Collatz_h */
