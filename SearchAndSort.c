/**
 *
 * Search and Sort
 * Joe Bobula
 *
 * contact@exit32studio.com
 *
 * Various search and sort functions from lecture
 **/
 
 /**
  *
  * swaps the values of int x and y
  *
  **/
 void swab(int x, int y);
 
 /**
  *
  * Performs binary search for "value" within the "values" array.
  * "n" is the number of items in the array
  *
  **/
 
 bool binarySearch(int value, int values[], int n)
 {
    //Set values for the top and bottom of the search
    int lower = 0;
    int upper = n - 1
    
    //Binary search
    while (lower <= upper)
    
        //Find the middle
        int middle = (upper + lower) / 2;
        
        //Compare middle to desired value
        if (value == values[middle])
        {
            return true;
        }
        //Desired value is less than the middle (go left)
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
 
 void swab (int x, int y)
 {
    
 }
 
