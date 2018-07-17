//
//  main.c
//  SearchAndSort
//
//  Created by Joseph Bobula on 6/24/18.
//  Copyright © 2018 Joseph Bobula. All rights reserved.
//

#include <stdio.h>
#include "SearchAndSort.h"
#include "Collatz.h"
#include <sys/time.h>
#include "CSVCreator.h"

#define NUMBER_OF_TESTS 10  //Number of repeat tests to perform for each method.  This is used for statistical analysis of algorithm speed
#define SALT_TO_FIND 700    //A number we force into the array for searching later
#define ITERATION_COUNT 1000 //Number of iterations of the test (how many data sets between 1 and MAX_NUMBER_OF_TESTS]

void runTest(int divisor);

void printElapsedTimes(unsigned long times[], int numberOfTestElements, char *unit) {
    for (int i = 0; i < numberOfTestElements; i++) {
        printf("Test %i was %lu%s\n", i, times[i], unit);
    }
}

int main(int argc, const char *argv[]) {
    //Iterate through all the test variants
    int increment = MAX_NUMBER_OF_NUMBERS / ITERATION_COUNT;
    for (int i = increment; i < MAX_NUMBER_OF_NUMBERS; i += increment) {
        runTest(i);
    }
}

void runTest(int complexity){
    //Get a local array size (number of numbers) and local times array size (number of tests + 1 for complexity column)
    int localNumberOfNumbers = complexity;
    int localNumberOfTests = NUMBER_OF_TESTS + 1;
    //Create a master array of arrays to store unsorted numbers
    int masterNumbers[NUMBER_OF_TESTS][localNumberOfNumbers];
    for (int i = 0; i < NUMBER_OF_TESTS; i++) {
        grabRandom(masterNumbers[i], localNumberOfNumbers);
    }
    
    //Insert a salt to find later in each array
    for (int i = 0; i < NUMBER_OF_TESTS; i++) {
        masterNumbers[i][0] = SALT_TO_FIND;
    }
    
    //Make a struct for holding start and end times
    struct timeval start, end;
    
    //create an array to use as a copy of the master
    int unsortedNumbers[localNumberOfNumbers];
    
    //Create another array to hold the elapsed times
    unsigned long times[localNumberOfTests];
    unsigned long elapsedTime;
    
    //Make a struct for holding the elapsed time and writing it to a file
    file_row myRow = {localNumberOfTests, times, ';'};
    
    //Put the number of numbers in the first column of the file
    times[0] = (long)localNumberOfNumbers;
    
    printf("Complexity %i\n", complexity);
    
    //Sort the array using selection sort
    for (int i = 0; i < NUMBER_OF_TESTS; i++) {
        duplicateArray(masterNumbers[i], unsortedNumbers, localNumberOfNumbers);
        gettimeofday(&start, NULL);
        selectionSort(unsortedNumbers, localNumberOfNumbers);
        gettimeofday(&end, NULL);
        elapsedTime = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
        times[i + 1] = elapsedTime;
    }
    //Write the times array to file
    writeRow(myRow, "SelectionSort.txt");
    
    //Sort a new array using bubble sort
    for (int i = 0; i < NUMBER_OF_TESTS; i++) {
        duplicateArray(masterNumbers[i], unsortedNumbers, localNumberOfNumbers);
        gettimeofday(&start, NULL);
        bubbleSort (unsortedNumbers, localNumberOfNumbers);
        gettimeofday(&end, NULL);
        elapsedTime = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
        times[i + 1] = elapsedTime;
    }
    //Write the times array to file
    writeRow(myRow, "BubbleSort.txt");
    
    //Sort a new array using insertion sort
    for (int i = 0; i < NUMBER_OF_TESTS; i++) {
        duplicateArray(masterNumbers[i], unsortedNumbers, localNumberOfNumbers);
        gettimeofday(&start, NULL);
        insertionSort(unsortedNumbers, localNumberOfNumbers);
        gettimeofday(&end, NULL);
        elapsedTime = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
        times[i + 1] = elapsedTime;
    }
    //Write the times array to file
    writeRow(myRow, "InsertionSort.txt");
    
    //Sort a new array using merge sort
    for (int i = 0; i < NUMBER_OF_TESTS; i++) {
        duplicateArray(masterNumbers[i], unsortedNumbers, localNumberOfNumbers);
        gettimeofday(&start, NULL);
        mergeSort(unsortedNumbers, 0, (localNumberOfNumbers - 1));
        gettimeofday(&end, NULL);
        elapsedTime = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
        times[i + 1] = elapsedTime;
    }
    //Write the times array to file
    writeRow(myRow, "MergeSort.txt");
}

