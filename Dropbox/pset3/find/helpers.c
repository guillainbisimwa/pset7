/*guilain 2014 6 jully*/
/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm ************************
    int begin = 0;
    int end = n-1;
    
    while(end >= begin)
    {
        int mid = (end + begin)/2;
        if (values[mid] == value)
        {
            return true;
        }
         if (values[mid] > value)
        {   
            end = mid-1;
        }
        if (values[mid]< value)
        {
            begin = mid+1;
        }
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm ***
    for(int i = 0;i<n;i++)
    {
        int small = values[i];
        int small_l = i;
        for(int j = i+1;j<n;j++)
        {
            if(small>values[j]) 
            {   
                small = values[j];
                small_l = j;
            }
        }
    values[small_l]=values[i];
    values[i]=small;
    }
    
    return;
}
