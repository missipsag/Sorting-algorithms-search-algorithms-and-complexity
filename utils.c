#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//swap the indexies of two value in an array
void swap ( int v[], int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

//print the elements of an array
void printArray (int v[], int arrSize) {
    for(int i = 0; i < arrSize ; i++) {
        printf(" %d \t", v[i]);
    }
    printf("\n");
}

//here we fill the array with random elements
void initialisation(int v [], int arrSize){

  srand(time(NULL));
  for(int i=0; i<arrSize; i++){ 
      v[i]=(rand()%100);
 }
}

//creating identical arrays
void copyArray(int v[], int v2[], int arrSize) {
    for(int i = 0; i < arrSize ; i++) {
       v2[i] = v[i];
    }   
}
