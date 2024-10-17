#include <stdio.h>
#include <stdlib.h>


// This function implements the Binary search algorithm 
// How it works :
// Basically it compares a given value as a parameter the the middle of the array 
  // if it is bigger then it goes to middle of the second part of the array
  // if it is less then it goes to the middle of first part of the array 
  // It repeats this until it finds the value 

int binarySearch(int val, int v[], int arrSize, int* nbr){  
  int i =0;
  int end=arrSize-1;
  int found=0;
  int middle;

  // check in the value to search is between the max and min values the sorted array
  if ( v[0] < val && v[end] > val) { 

    while ( found == 0 && end != middle) { 

     ( *nbr)++;        //increment the number of iterations of this functions
      middle = (end + i) / 2;
      if(v[middle] == val) {   //check if the value at v[middle] equals to val
        found = 1; 
        return middle;

      } else {   
          if (v[middle] < val) {
            i = middle;
          } else { 
            end = middle;
          }
      }     
    }
  } else { // return -1 if the value to search is not in the sorted array
    printf("\nThe value doesn't exist in the list\n");
    return -1;
  }
}
    
