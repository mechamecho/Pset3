/**
 * helpers.c
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
    //Binary search for value

    int start=0;
    int end= n-1;
    int currentValueI=(start+end)/2;

    //if size of array is negative return false
    if(n<0)
    {
        return false;
    }

    //while there is at least one element left to compare to
    while((end-start)>=0)
    {

        //if value in the middle of the current part of the array is the searched value, return true
        if(values[currentValueI]==value)
        {
            return true;
        }

        //else, if current value, greater than search value, look at only the left side of array, and repeat the search process(recursion)
        else if(values[currentValueI]>value)
        {
            end=currentValueI-1;

        }

        //else, the searched value must be greater than the current value, so repeat search process for right side of the array
        else
        {
            start=currentValueI+1;

        }
        currentValueI=(start+end)/2;

    }


    //if not found until there are no elements left to check, return false
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Selection sort algorithm

    //shows where the unsorted elements are

    //initial value for currentMinimum
    int min=values[0];
    int minIndex=0;
    int temp=0;

    //index of first unsorted element
    int start=0;


    for(int i=0; i<n; i++)
    {
        //repeatedly look for minimum value in array, and put it at the beginning of the unsorted part of the unsorted part of the array

        for(int j = start; j<n; j++)
        {

            //if value is smaller than the minimum, minimum becomes the current value
            if(values[j]<min)
            {
                minIndex=j;
                min=values[j];
            }
        }


        //swaps first unsorted element, with the minimum value of the unsorted part of the array
        temp=values[minIndex];
        values[minIndex]=values[i];
        values[i]=temp;

        //updates the index of the first unsorted element after swapping the values above
        start++;
        //updates minimum value, and minimum index to the value, and index of the first unsorted element in the array
        min=values[start];
        minIndex=start;
    }

    //debugging
/*
for (int i=0; i<n; i++)
    {
        printf("Element%i : %i \n", i, values[i]);
    }
*/

    return;
}
