/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // check if n is a possible value, n has to be positive
    if(n < 0){
        return false;
    }
    
    // initialize min and max as array indeces
    int min = 0;
    int max = n-1;
    
    //binary search loop
    while(min <= max){
        int midpoint = (min+max)/2;
        int mid = values[midpoint];
        if(value > mid){
            min = midpoint + 1;
        }
        
        else if(value<mid){
            max = midpoint - 1;
        }
        
        else return true;
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // initialize our temporary variable and a counter for amount of swaps
    int temp;
    bool check = true;
    
    // while loop to iterate until there are no more steps
    
    while(check){
        
        check = false;
       // bubble sorting algorithm
        for(int i = 0; i < (n-1); i++){
            if(values[i] > values[i+1]){
                temp = values[i];
                values[i] = values[i+1];
                values[i+1] = temp;
                check = true;
            }
        }
    }
}