#include <stdio.h>
#include <stdlib.h>

// This function implements the radix sort algorithm.
// How it works:
// Sort the elements by their least significant digit (using a stable sorting algorithm like counting sort).
// Move to the next significant digit and repeat.
// Continue until the most significant digit is sorted.
//
// This algorithm has a time complexity of : O(d * (n + k)) where d is the number of digits, n is the number of elements, and k is the range of digits.
// It is a stable sort.

void swap(int v[], int i, int j);                  // Unused here, Radix Sort uses counting sort internally.

void countingSortForRadix(int v[], int n, int exp) {
    int output[n];                                   // Output array to store sorted numbers
    int count[10] = {0};                             // Count array for digits (0 to 9)

    for (int i = 0; i < n; i++) count[(v[i] / exp) % 10]++;  // Count occurrences of each digit

    for (int i = 1; i < 10; i++) count[i] += count[i - 1];     // Update count array

    for (int i = n - 1; i >= 0; i--) {               // Build the output array
        output[count[(v[i] / exp) % 10] - 1] = v[i];
        count[(v[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) v[i] = output[i];   // Copy sorted array
}

void radixSort(int v[], int n) {
    int maxVal = v[0];                            // Find the maximum number
    for (int i = 1; i < n; i++)
        if (v[i] > maxVal) maxVal = v[i];

    for (int exp = 1; maxVal / exp > 0; exp *= 10)  // Sort for every digit
        countingSortForRadix(v, n, exp);
}
