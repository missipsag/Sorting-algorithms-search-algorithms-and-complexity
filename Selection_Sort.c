#include <stdio.h>
#include <stdlib.h>

// This function implements the selection sort algorithm.
// How it works : 
// We set the the index of first value of the list to be the index of the min element.
// Then we check if the next element (let's call it temp for the sake of explanation) is less than this value,
    // if yes : we set the index min to the index of temp.
    // then we swap between the current min and at the temp index.
// Then we repeat the process for min elment is at (indexMin +1).

// --> this algorithm has the time complexity of O(n^2) in the worst case.
//  It is a not stable sorting algorithm, it doesn't maintain the relative order of equal elements.

extern void swap(int v[], int i, int j);

void selectionSort(int v[], int arrSize) {
    for(int i = 0; i < arrSize - 1; i++){
        int minIndex = i;                            // set v[i] to be the min value
        
        for(int j = i +1; j< arrSize; j++){
            if(v[j] < v[minIndex]) {
                minIndex = j;                        // set minIndex to j 
                swap(v, j, minIndex);                // swap values           
            }
            
        }   
    }
}