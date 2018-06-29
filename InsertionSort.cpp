// InsertionSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

#define MAX_NUMBER_OF_NUMBERS 10
#define MAX_NUMBER_VALUE 100


int _tmain(int argc, _TCHAR* argv[])
{
	//Create an array of random numbers
	int unsortedNumbers[MAX_NUMBER_OF_NUMBERS];

	//Create an array to hold the sorted numbers
	int sortedArray[MAX_NUMBER_OF_NUMBERS];

	srand(time(NULL));
	for (int i = 0; i < MAX_NUMBER_OF_NUMBERS; i++) {
		unsortedNumbers[i] = rand() % MAX_NUMBER_VALUE;
		//Also be a good boy and fill the sorted array with zeroes
		sortedArray[i] = 0;
	}

	//The first number is always considered sorted
	sortedArray[0] = unsortedNumbers[0];

	//Loop through the unsorted array
	for (int i = 1; i < MAX_NUMBER_OF_NUMBERS; i++) {
		//Create a placeholder for the sort position
		int sortedPosition = i;
		
		//Compare the unsorted number against the sorted array until it finds a home
		while ((unsortedNumbers[i] < sortedArray[sortedPosition - 1]) && (sortedPosition > 0)) {
			sortedArray[sortedPosition] = sortedArray[sortedPosition - 1];
			sortedPosition--;
		}
		sortedArray[sortedPosition] = unsortedNumbers[i];
	}

	return 0;
}

