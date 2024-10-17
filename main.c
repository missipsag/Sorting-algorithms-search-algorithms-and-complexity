#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void copyArray(int v[], int v2[], int arrSize);
void initialisation(int v[], int arrSize);
void printArray(int v[], int arrSize);
int binarySearch(int val, int v[], int arrSize, int* nbr2);
int sequentialSearch(int val, int v[], int arrSize, int* nbr1);
void mergeSort(int v[], int g, int d );
void bubbleSort(int v[], int arrSize);
void insertionSort(int v[], int arrSize);
void quickSort(int v[], int left, int right);
void selectionSort(int v[], int arrSize);
void shellSort(int v[], int n);
void heapSort(int v[], int n);
void radixSort( int v[], int n);


void main(){

  int arrSize;                       // length of the array

  printf("\n Enter the size of the array to sort : \t");
  scanf("%d", &arrSize);
  
  int nbr1 = 0;                       // number of iteration of SeqSearch function
  int nbr2 = 0;                       // number of iteration of DichoSearch funtion
  clock_t t1,t2;
  double TE1;
  int tab[arrSize];
                            
  initialisation(tab, arrSize);     //fill the array with random values

 
  printf("\n Which sorting algorithm to use : \n");
  printf("  0) Exit \n  1) Bubble sort \n  2) Merge sort  \n  3) Insertion sort  \n  4) Quick sort  \n  5) Selection sort  \n  6) Heap sort  \n  7) Shell sort  \n  8) Radix sort  \n");
  
  
                  
  int tab2[arrSize];          
 
  int choice = 99;                           //give it a random value other than between 0 to 9
  scanf("%d", &choice);

  while(choice != 0) {
    copyArray(tab, tab2, arrSize);             //creating a copy of the array to sort
    switch(choice) {
      case 0: 
        break;

      case 1: 
        t1 = clock();
        bubbleSort(tab2, arrSize);
        t2 = clock();
        printf("\n The sorted array : \n");
        printArray(tab2, arrSize);

        TE1= ((double)(t2-t1))/CLOCKS_PER_SEC;  //Converting the amount of time took by each algorithm into seconds
        printf("\nThis algorithm took %f s\n", TE1);
        break;

      case 2: 
        t1 = clock();
        mergeSort(tab2, 0, arrSize-1);
        t2 = clock();
        printf("\n The sorted array : \n");
        printArray(tab2, arrSize);

        TE1= ((double)(t2-t1))/CLOCKS_PER_SEC;  //Converting the amount of time took by each algorithm into seconds
        printf("\nThis algorithm took %f s\n", TE1);
        break;

      case 3: 
        t1 = clock();
        insertionSort(tab2, arrSize);
        t2 = clock();
        printf("\n The sorted array : \n");
        printArray(tab2, arrSize);

        TE1= ((double)(t2-t1))/CLOCKS_PER_SEC;
        printf("\nThis algorithm took %f s\n", TE1);
        break;

      case 4: 
        t1 = clock();
        quickSort(tab2, 0, arrSize -1);
        t2 = clock();
        printf("\n The sorted array : \n");
        printArray(tab2, arrSize);

        TE1= ((double)(t2-t1))/CLOCKS_PER_SEC;
        printf("This algorithm took %f s", TE1);
        break;
        
      case 5:
        t1 = clock();
        selectionSort(tab2, arrSize);
        t2 = clock();
        printf("\n The sorted array : \n");
        printArray(tab2, arrSize);

        TE1= ((double)(t2-t1))/CLOCKS_PER_SEC;
        printf("\nThis algorithm took %f s\n", TE1);
        break;

      case 6: 
        t1 = clock();
        heapSort(tab2, arrSize);
        t2 = clock();
        printf("\n The sorted array : \n");
        printArray(tab2, arrSize);

        TE1= ((double)(t2-t1))/CLOCKS_PER_SEC;
        printf("\nThis algorithm took %f s\n", TE1);
        break;
      
      case 7: 
        t1 = clock();
        shellSort(tab2, arrSize);
        t2 = clock();
        printf("\n The sorted array : \n");
        printArray(tab2, arrSize);

        TE1= ((double)(t2-t1))/CLOCKS_PER_SEC;
        printf("\nThis algorithm took %f s\n", TE1);
        break;

      case 8: 
        t1 = clock();
        radixSort(tab2, arrSize);
        t2 = clock();
        printf("\n The sorted array : \n");
        printArray(tab2, arrSize);

        TE1= ((double)(t2-t1))/CLOCKS_PER_SEC;
        printf("\nThis algorithm took %f s\n", TE1);
        break;  
      
      default : 
        printf("\n Please enter a number between 0 to 9\n");  
    }
    printf("\nWhich algorithm to use next (Enter 0 to exit) : \t");
    scanf("%d", &choice);
  }

  int index = 0;                                  
  choice = 99; 
  int val = 0;
  printf(" \n Which searching algorithm to use (Enter 0 to exit) : \n 1) Sequential search \n 2) Binary search \n ");
  scanf("%d", &choice);

  while (choice != 0) {
    if (val == 0) {
      printf("\nEnter a value to search : \t");
      scanf("%d", &val);
    }
    switch(choice) {
      case 0: break;

      case 1: 
        t1 = clock();
        index = sequentialSearch(val, tab2, arrSize, &nbr1);
        t2 = clock();
        TE1= ((double)(t2-t1))/CLOCKS_PER_SEC;
        printf("\nThe value %d is at index %d \n", val, index);
        printf("\n this alogorithm took : %f s\n", TE1);
        printf("\n this algorithm did %d iterations", nbr1);
        break;
      
      case 2: 
        t1 = clock();
        index = binarySearch(val, tab2, arrSize, &nbr2);
        t2 = clock();
        TE1= ((double)(t2-t1))/CLOCKS_PER_SEC;
        printf("\n The value %d is at index %d \n", val, index);
        printf("\n this alogorithm took : %f s\n", TE1);
        printf("\n this algorithm did %d iterations", nbr2);
        break;
      
      default : 
        printf("\n Please enter a number between 0 to 1 (enter 0 to exit) : \t");
        scanf("%d",choice);
    }
    printf("\n Which search algorithm to use next (enter 0 to exit) : \t");
    scanf("%d", &choice);
  }
}