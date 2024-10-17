#include <stdio.h>
#include <stdlib.h>

// This function implements the merge sort algorithm, also called the partition-exchange sort.
// It is based on the idea of : devide to conquer.
// How it works : 
// We select a pivot element in the list, here we select the last element.
// Then we partition every the other elements into two sub-lists, using recursive calls, according to whether they are less or greater then the pivot. 
// The process stops we get single elements lists. Then we sort the sub lists back into the wanted order.  

// --> this algorithm has a time complexity of O(n^2) in the worst case.
//  It is a stable sorting algorithm that maintains the relative order of equal elements.




extern void swap(int v[], int i, int j);

int partition(int v[], int left, int right){
    int pivot = v[right];                       // select the pivot as the element at the right
    int i = (left - 1);                         // initialize a varibale to store the index of i-1, for swapping
    
    for(int j = left; j < right; j++) {         // loop through list 
        if(v[j] <= pivot){                      // if v[j] is inferior to the pivot 
            i++;                                    // increment i in order to swap 
            swap(v, i, j);                          
        }
    }
    swap(v, i+1, right);                        // after we looped through the list, swap the pivot with i+1
    return (i+1);                               // retutn the index of the pivot value
}

void quickSort(int v[], int left, int right){

    if (left < right) {                         
        int pivot = partition(v, left, right);  // partition the list
        quickSort(v, left, pivot - 1);
        quickSort(v, pivot + 1, right);
    }
}