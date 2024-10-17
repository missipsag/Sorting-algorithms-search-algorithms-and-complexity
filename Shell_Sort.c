#include <stdio.h>
#include <stdlib.h>

// This function implements the shell sort algorithm.
// How it works:
// Start with a large gap and reduce it gradually.
// Compare elements that are gap distance apart, and swap them using swap() if needed.
// Continue reducing the gap until it becomes 1, which performs an insertion sort.
//
// This algorithm has a time complexity in worse case scenario of O(n^2) and average/best case scenario of O(nlog n).
// It is not a stable sort.


void shellSort(int v[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {    // Start with large gap, reduce by half
        for (int i = gap; i < n; i++) {           // Perform gapped insertion sort
            int temp = v[i];                    // Store current element
            int j;
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                v[j] = v[j - gap];            // Shift elements to right
            }
            v[j] = temp;                        // Place temp at its correct position
        }
    }
}
