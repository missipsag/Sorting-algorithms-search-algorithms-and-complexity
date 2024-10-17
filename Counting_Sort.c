#include <stdio.h>
#include <stdlib.h>

// This function implements the counting sort algorithm.
// How it works:
// Find the range of input values.
// Create a count array to store the frequency of each element.
// Modify the count array such that each index stores the sum of previous counts (to position the elements).
// Build the output array using the count array.
//
// This algorithm has a time complexity of: O(n + k), where n is the number of elements and k is the range of the input.
// It is a stable sort.

void countingSort(int v[], int n, int maxVal) {
    int count[maxVal + 1];                                  // Create count array
    int output[n];                                          // Create output array
    for (int i = 0; i <= maxVal; i++){
        count[i] = 0;                                       // Initialize count array
    } 

    for (int i = 0; i < n; i++){
        count[v[i]]++;                                      // Store count of each element
    } 

    for (int i = 1; i <= maxVal; i++){
        count[i] += count[i - 1];                           // Update count array
    } 

    for (int i = n - 1; i >= 0; i--) {                      // Build the output array
        output[count[v[i]] - 1] = v[i];
        count[v[i]]--;
    }

    for (int i = 0; i < n; i++) {
        v[i] = output[i];                                   // Copy the sorted array
    } 
}