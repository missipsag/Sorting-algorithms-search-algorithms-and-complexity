#include <stdio.h>
#include <stdlib.h>

// This function implements the heap sort algorithm.
// How it works:
// Build a max heap from the input data.
// The largest item is stored at the root, swap it with the last item using swap().
// Reduce the size of the heap by 1 and heapify the root.
// Repeat until the heap size is reduced to 1.
//
// This algorithm has a time complexity of  O(n log n) for average and worst case.
// It is not a stable sort.

void swap(int v[], int i, int j);

void heapify(int v[], int n, int i) {
    int largest = i;              // Assume the root is the largest
    int left = 2 * i + 1;         // Left child
    int right = 2 * i + 2;        // Right child

    if (left < n && v[left] > v[largest]) 
        largest = left;           // If left child is larger

    if (right < n && v[right] > v[largest])
        largest = right;          // If right child is larger

    if (largest != i) {           // If the largest is not the root
        swap(v, i, largest);    // Swap root with the largest
        heapify(v, n, largest); // Continue heapifying the subtree
    }
}

void heapSort(int v[], int arrSize) {
    // Build max heap
    for (int i = arrSize / 2 - 1; i >= 0; i--) {
        heapify(v, arrSize, i);
    }

    // Extract elements from the heap one by one
    for (int i = arrSize - 1; i > 0; i--) {
        swap(v, 0, i);          // Move current root to the end
        heapify(v, i, 0);       // Heapify the reduced heap
    }
}
