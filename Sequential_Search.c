#include <stdio.h>
#include <stdlib.h>

// here we impelement the sequential search algorithm 
// We basically initialize a counter in the beginning of the array (at index 0) 
// Then we compare the value at that index to the given value to seach 
    //if it is equal, we return the counter 
    //if it is not equal we increment the counter and repaeat the process

int sequentialSearch(int val, int v[], int arrSize, int* nbr){
  
  int end = arrSize-1;
  int found = 0; 
  int i =0 ;
  
  if ( v[0] < val && v[end] > val) { 
    while( found == 0 && i < arrSize) {
      if(v[i] == val) {
        found = 1;
        return i;                  //return the index of the first matching value
      } else {
        (*nbr)++;                 // increment the number of iterations
        i++;  
      }
    }
  } else {
    printf("\nThe value doesn't exist in the list\n");
    return -1;
  }
}