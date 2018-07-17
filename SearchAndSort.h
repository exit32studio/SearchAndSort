//
//  SearchAndSort.h
//  SearchAndSort
//
//  Created by Joseph Bobula on 6/30/18.
//  Copyright © 2018 Joseph Bobula. All rights reserved.
//
//  Various Search and Sort algorithms for working with arrays of numbers

#ifndef SearchAndSort_h
#define SearchAndSort_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RANDOM_VALUE 10000
#define MAX_NUMBER_OF_NUMBERS 5000


//####### HELPER METHODS #######
//Duplicate an array
void duplicateArray(int arrayToCopy[], int destinationArray[], int numberOfElements);

//Print out an array
void printArray(int arrayToPrint[], int numberOfElements);

//Fill an array with random numbers
void grabRandom (int unsortedNumbers[], int numberOfPositions);


//####### SORTS #######
//Performs selection sort on passed array
void selectionSort (int unsortedNumbers[], int numberOfPositions);

//Performs bubble sort on passed array
void bubbleSort (int unsortedNumbers[], int numberOfPositions);

//Performs insertion sort on passed array
void insertionSort (int unsortedNumbers[], int numberOfPositions);

//Uses merge sort on the passed array
void mergeSort (int unsortedNumbers[], int left, int right);

//####### SEARCHES #######
//Uses linear search to return the position of the element in the passed array.  Returns -1 if it cannot find the element
int linearSearch (int arrayToSearch[], int numberOfElements, int elementToFind);

//Uses binary search to return the position of the element in the passed array.  Returns -1 if it cannot find the element.
//Reminder that the array of numbers must be sorted in order for binary search to work
int binarySearch (int arrayToSearch[], int numberOfElements, int elementToFind);

#endif /* SearchAndSort_h */
