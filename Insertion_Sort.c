#include <stdio.h>
#include <stdlib.h>

// This function implements the insertion sort algorithm 
// How it works : 
// It compares the value in turn, starting with the second value in the list.
// It checks if this value is lesser then the values at the left of it 
    // if yes : it moves this value is repeatedly moved into the left until it meets a values that is less than it.
    // if no : no changes are made.
// This process starts again with the next value.

// --> this algorithm has the time complexity of O(n^2) in the worst case and O(n) in the best case.
//  It is a stable sorting algorithm that maintains the relative order of equal elements.

void insertionSort(int v[], int arrSize) {
    for(int i = 1; i < arrSize; i++){
        int tmp = v[i];    // select the value at index i
        int j = i - 1;     // select the at index i-1

        while (tmp < v[j] && j>=0) {
            v[j+1] = v[j]; // if v[i] < v[j] move v[j] to the right
            j--;           // go the left value of j and compare it to v[i] again
        }
        v[j+1] = tmp;      // if the a value that is less than v[i] is met or we are at the at the beginning of the list 
                           //   assing the value of v[i] at this index

    }
}