/**
 *
 * Search and Sort
 * Joe Bobula
 *
 * contact@exit32studio.com
 *
 * Various search and sort functions from Harvard University CS50
 **/
 
 #include <stdbool.h>
 
 /**
  *
  * Performs binary search for "value" within the "values" array.
  * "n" is the number of items in the array
  *
  **/
 
int main(void)
{
   return 0;
}
 
 
/**
 * Binary search
 **/
bool binarySearch(int value, int values[], int n)
{
   //Set values for the top and bottom of the search
   int lower = 0;
   int upper = n - 1;
    
   //Binary search
   while (lower <= upper)
   {
       //Find the middle
       int middle = (upper + lower) / 2;
        
       //Compare middle to desired value
       if (value == values[middle])
       {
           return true;
       }        //Desired value is less than the middle (go left)
       else if (value < values[middle])
       {
           //Make the upper bound left of the middle
           upper = middle - 1;
       }
       //Desired value is greater than the middle (go right)
       else if (value > values[middle])
       {
            //Make the lower bound right of the middle
            lower = middle + 1;
       }
   }
    
   //If the search completes without finding the value, return false
   return false;
}
 

/**
 *  Insertion Sort
 **/
 
void insertionSort(int array[]; int size)
{
    //Iterate through the array
    for (int i = 0; i < size - 1; i++)
    {
        //Start with the first position in the array
        int element = array[i];
        int position = i;
        
        //Grab the smallest number in the array and swap it to the left
        while ((position > 0) && (array[position - 1] > element)
        {
            array[position] = array[position - 1];
            position = position - 1;
            array[position] = element
        }
    }
}

 
/**
 *  Selection Sort
 **/
void selectionSort(int array[], int size)
{
   //iterate over the array
   for (int i = 0; i < size - 1; i++)
   {
       //smallest element and its position in sorted array
       int smallest = array[i];
       int position = i;
        
       //look through unsorted part of array
       for (int k = i + 1; k < size - 1; k++)
       {
           //find the next smallest element
           if (array[k] < smallest)
           {
               smallest = array[k];
               position = k;
           }
       }   
       //swap
       int temp = array[i];
       array[i] = smallest;
       array[position] = temp;
   }
}


/**
 * Bubble Sort
 **/ 
void bubbleSort(int array[], int n)
{
   //cycle through the array
   for (int k = 0; k < n - 1; k++)
   {
       //optimize; check if there are no swaps
       int swaps = 0;
        
       //swap adjacent elements if out of order
        
           //iterate through the array
           for (int i = 0; i < n - 1 - k; i++)
           {
               //check if array[n] and array[n+1] are in order
               if (array[n] > array[n+1])
               {
                   //Swap the values
                   int temp = array[n+1];
                   array[n+1] = array[n];
                   array[n] = temp;
               }
           }
           
       //Optimization - break if no swaps are made
       if (!swaps)
       {
           break;
       }
   }
}
