#include <stdio.h>
#include <stdlib.h>

// This function implements the merge sort algorithm 
// It's a more complex sorting algorithm, but highely efficient. It's main idea is : devide to conquer.
// How it works : 
// The list is repeatedly devided into two until all the element are separated individually using recursive calls.
// Then every pair is sorted then placed into a bigger a bigger list.
// This process is done to every pair of lists until we get the sorted version of the initial list.

// --> this algorithm has a time complexity of O(nlog(n)) in the worst case.
//  It is a stable sorting algorithm that maintains the relative order of equal elements.



extern void printArray(int v[], int arrSize);

//this function implements the merge sort algorithm 
  //the way that it works is we devide the array into small arrays to sort 
  //then we merge the sorted small array to the sorted big array
  
void merge( int v[], int left, int mid, int right){
  int j, k, i;
  int n1 = mid - left + 1;       // the size of the left array
  int n2 = right - mid;          // the size of the right array
  int vleft[n1], vright[n2];

  for( i=0; i < n1; i++ ){
    vleft[i] = v[left +i];       // fill the left array with the n1 elements at the further left of v
  }

  for( j=0; j<n2; j++ ) {
    vright[j] = v[ mid + 1 + j ]; //fill the right array with n2 elements at the further right of v
  }

  i = 0; 
  j = 0;
  k = left;                        // set to left to push new sorted element into the v array

  while( i<n1 && j<n2 ){           // sorting then merging the smaller arrays together
    if(vleft[i] <= vright[j]){
      v[k] = vleft[i];
      i++;
     } else {
        v[k] = vright[j];
        j++;
      }
    k++;
   }
    while( i < n1 ){                // if the vright element are all sorted in v array
      v[k] = vleft[i];
      i++;
      k++;
    }
    while( j < n2 ){                // if the vleft elements are all sorted in v array
      v[k] = vright[j];
      j++;
      k++;
    }
}
  
//this function helps the the merge sort function by deviding the given array to sort into litte arrays
// by making recursive calls  whith new indices 

void mergeSort(int v[], int left, int right){

  // devide the array into smaller ones, stop when left = right 
  if( left < right){
    int mid = ( left + right )/2;
    mergeSort(v, left, mid);
    mergeSort(v, mid + 1, right);
    merge(v, left, mid, right);
  }  
}



