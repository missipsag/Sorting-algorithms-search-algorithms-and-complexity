#include <stdio.h>
#include <stdlib.h>

// This function implements the bubble sort algorithm 
// How it works : 
// It compares every two adjacent element of the list starting at the first value.
    // if this value is  greater than the value at the right of it : it will swap them.
    // if not : no changes are made, we increment the value of the iterator and repeat the process.

// --> this algorithm has the time complexity of O(n^2) in the worst case.
//  It is a stable sorting algorithm that maintains the relative order of equal elements.


extern void swap(int v[], int i, int j);
extern void printArray(int v[], int arrSize);

void bubbleSort(int v[], int arrSize) {
    int swapped = 0;                        // bool variable in order to stop the loop from iterating if no swap in needed

    for (int i = 0; i < arrSize; i++) {
        swapped = 0;

        //the 2nd loop only needs to run (arrSize -i -1) times 
        //to illustrate : at the second iteration the last element will always 
        // be the greatest value ( because in our case, we sort in ascending order)
        // at the second iteration the arrSize-1 element is the greatest value after the last element and so on and so forth
        
        for (int j = 0; j < (arrSize -1 -i); j++) {
            if (v[j] > v[j + 1]){
                swap(v, j, j + 1);
                swapped = 1;
            }
        }
        if (swapped == 0) break ;           // stop the algorithm if no swapping is needed
    }
    printf("\n Bubble Sort algorithm : \n");
    printArray(v, arrSize);
}
 
