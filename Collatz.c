//
//  Collatz.c
//  SearchAndSort
//
//  Created by Joseph Bobula on 6/30/18.
//  Copyright © 2018 Joseph Bobula. All rights reserved.
//

#include "Collatz.h"

int collatz(unsigned int n) {
    if (n == 1) {
        //Stop the loop.  BASE CASE
        return 0;
    } else if (n % 2 == 0) {
        //Handle even numbers
        return 1 + collatz(n/2);
    } else {
        //Handle odd numbers
        return 1 + collatz((3*n +1));
    }
}

void numberOfSteps(int numbersToTest[], int numberOfElements, int *buffer) {
    for (int i = 0; i < numberOfElements; i++) {
        buffer[i] = collatz(numbersToTest[i]);
    }
}

