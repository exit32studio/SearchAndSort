//
//  SearchAndSort.c
//  SearchAndSort
//
//  Created by Joseph Bobula on 6/30/18.
//  Copyright © 2018 Joseph Bobula. All rights reserved.
//


#include "SearchAndSort.h"

//####### HELPER METHODS #######
void printArray(int arrayToPrint[], int numberOfElements) {
    for (int i = 0; i < numberOfElements; i++) {
        printf("Element %i is %i\n", i, arrayToPrint[i]);
    }
}

void grabRandom (int unsortedNumbers[], int numberOfPositions) {
    //Fill the array with random numbers
    srand((unsigned)time(NULL));
    
    for (int i = 0; i < numberOfPositions; i++) {
        unsortedNumbers[i] = rand() % MAX_RANDOM_VALUE;
    }
}

void duplicateArray(int arrayToCopy[], int destinationArray[], int numberOfElements) {
    for (int i = 0; i < numberOfElements; i++) {
        destinationArray[i] = arrayToCopy [i];
    }
}

//####### SORTS #######

void selectionSort (int unsortedNumbers[], int numberOfPositions) {
    //Use an int to remember the location of the smallest number and another to remember the location in the sorted array
    int smallestNumber = 0;
    int numberToSwap = 0;
    int numberOfSwaps = 0;
    
    //Flip through the numbers and find the smallest one
    for (int i = 0; i < numberOfPositions; i++) {
        smallestNumber = unsortedNumbers[i];
        for (int j = i; j < numberOfPositions; j++) {
            if (smallestNumber > unsortedNumbers[j]) {
                numberToSwap = smallestNumber;
                smallestNumber = unsortedNumbers[j];
                unsortedNumbers[j] = numberToSwap;
                numberOfSwaps++;
            }
        }
        unsortedNumbers[i] = smallestNumber;
    }
}

void bubbleSort (int unsortedNumbers[], int numberOfPositions) {
    //Variables to hold biggest number the end position for looking in the array, and the number of swaps
    int endOfSortArea = numberOfPositions - 1;
    int numberToSwap = 0;
    int numberOfSwaps = 0;
    
    do {
        //Reset the number of swaps
        numberOfSwaps = 0;
        for (int i = 0; i < endOfSortArea; i++) {
            //Compare two adjacent numbers and swap them if necessary
            if (unsortedNumbers[i] > unsortedNumbers[i + 1]) {
                //Swap the numbers and increment the swap counter
                numberToSwap = unsortedNumbers[i + 1];
                unsortedNumbers[i + 1] = unsortedNumbers[i];
                unsortedNumbers[i] = numberToSwap;
                numberOfSwaps++;
            }
        }
        //Decrement the end of the sort area
        if (endOfSortArea > 0) {
            endOfSortArea--;
        }
    } while (numberOfSwaps > 0);
}

void insertionSort (int unsortedNumbers[], int numberOfPositions) {
    //Create an array to hold the sorted numbers
    int sortedArray[numberOfPositions];
    
    //The first number is always considered sorted
    sortedArray[0] = unsortedNumbers[0];
    
    //Create a placeholder for the sort position
    int sortedPosition;
    
    //Loop through the unsorted array
    for (int i = 1; i < numberOfPositions; i++) {
        //Make the sort position match the position in the unsorted array
        sortedPosition = i;
        
        //Compare the unsorted number against the sorted array until it finds a home
        while ((unsortedNumbers[i] < sortedArray[sortedPosition - 1]) && (sortedPosition > 0)) {
            sortedArray[sortedPosition] = sortedArray[sortedPosition - 1];
            sortedPosition--;
        }
        sortedArray[sortedPosition] = unsortedNumbers[i];
    }
    
    //Write over the unsorted elements (not too efficient, but it works)
    for (int i = 0; i < numberOfPositions; i++) {
        unsortedNumbers[i] = sortedArray[i];
    }
}

//Merge two subarrays into one.
//First array is left -> middle
//Second array is left +1 -> right
void merge (int numbersToMerge[], int left, int middle, int right) {
    //Create placeholders for positions in the sub arrays (used during merge)
    int leftIndex, rightIndex, mergeIndex;
    
    //Get values for the lengths of the sub arrays
    int leftLength = middle - left + 1;
    int rightLength = right - middle;
    
    //Copy the array to merge into temp arrays
    int leftArray[leftLength], rightArray[rightLength];
    for (int i = 0; i < leftLength; i++) {
        leftArray[i] = numbersToMerge[left + i];
    }
    for (int i = 0; i < rightLength; i++) {
        rightArray[i] = numbersToMerge[middle + 1 + i];
    }
    
    //Merge the two temporary arrays back into the passed array
    //Note that when one side gets empty, we drop out of the loop
    //Numbers remaining in either array are just dumped into the unsorted array after one side is empty
    leftIndex = 0;
    rightIndex = 0;
    mergeIndex = left;
    while (leftIndex < leftLength && rightIndex < rightLength) {
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
                      numbersToMerge[mergeIndex] = leftArray[leftIndex];
                      leftIndex++;
        } else {
            numbersToMerge[mergeIndex] = rightArray[rightIndex];
            rightIndex++;
            
        }
        mergeIndex++;
    }
    
    //Copy remaining parts of left or right array into the passed array
    while (leftIndex < leftLength) {
        numbersToMerge[mergeIndex] = leftArray[leftIndex];
        leftIndex++;
        mergeIndex++;
    }
    while (rightIndex < rightLength) {
        numbersToMerge[mergeIndex] = rightArray[rightIndex];
        rightIndex++;
        mergeIndex++;
    }
}

void mergeSort (int unsortedNumbers[], int left, int right) {
    if (left < right) {
        //Get the middle
        int middle = left + (right - left) / 2;
        
        //Merge sort the left
        mergeSort(unsortedNumbers, left, middle);
        
        //Merge sort the right
        mergeSort(unsortedNumbers, middle + 1, right);
        
        //Merge the two together
        merge(unsortedNumbers, left, middle, right);
    }
}


//####### SEARCHES #######
//Linear search
int linearSearch (int arrayToSearch[], int numberOfElements, int elementToFind) {
    //Make an int to hold our return value.  We like programming where there's only one return statement.  Default to assuming the element was not found.
    int searchPosition = -1;
    for (int i = 0; i < numberOfElements; i++) {
        if (arrayToSearch[i] == elementToFind) {
            searchPosition = i;
            break;
        }
    }
    return searchPosition;
}

//Binary search
int binarySearch (int arrayToSearch[], int numberOfElements, int elementToFind) {
    //Make an int to hold our return value.  We like programming where there's only one return statement.  Default to assuming the element was not found
    int searchPosition = -1;
    
    //Make two ints to hold the start and end of our "search array".  Start with the full passed array and then keep cutting the problem in half.
    int startPosition = 0;
    int endPosition = numberOfElements;
    
    //If the end position is ever less than the start position, then the element to find is not in the array
    while (startPosition <= endPosition) {
        //Use an int to hold the middle position of the array
        int midPoint = (startPosition + endPosition) / 2;
        
        //If the mid point of the array is what we want, save it's position and quit the loop
        if (arrayToSearch[midPoint] == elementToFind) {
            searchPosition = midPoint;
            break;
        //If the element to find is less than the mid point then it's in the left half of the array.  Move the end point left!
        } else if (elementToFind < arrayToSearch[midPoint]) {
            endPosition = midPoint - 1;
        //If the element to find is greater than the mid point, then it's in the right half of the array.  Move the start point right!
        } else if (elementToFind > arrayToSearch[midPoint]) {
            startPosition = midPoint + 1;
        }
    }
    
    //Return the position of the found number (or -1 if it wasn't found);
    return searchPosition;
}







