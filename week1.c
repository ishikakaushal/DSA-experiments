// sort an array of integars using bubble sort
#include <stdio.h> 
void bubbleSort(int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        int swapped = 0;  
        for (int j = 0; j < n - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) { 
                // Swap elements 
                int temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
                swapped = 1; 
            } 
        } 
        if (swapped == 0) { 
            break; 
        } 
    } 
} 
 
int main() { 
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    bubbleSort(arr, n); 
    printf("Sorted array: "); 
    for (int i = 0; i < n; i++) { 
    printf("%d ", arr[i]); 
    } 
    printf("\n"); 
    return 0; 
} 




// sort an array of integars using selection sort
#include <stdio.h> 
void selectionSort(int arr[], int n) { 
 int i, j, minIndex, temp; 
 for (i = 0; i < n - 1; i++) { 
        minIndex = i;   
        for (j = i + 1; j < n; j++) { 
            if (arr[j] < arr[minIndex]) { 
                minIndex = j; 
         } 
    } 
      if (minIndex != i) { 
      temp = arr[i]; 
      arr[i] = arr[minIndex]; 
        arr[minIndex] = temp; 
        } 
    } 
} 
void printArray(int arr[], int n) { 
   for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    } 
   printf("\n"); 
} 
int main() { 
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    printf("Original array: "); 
    printArray(arr, n); 
    selectionSort(arr, n); 
    printf("Sorted array: "); 
    printArray(arr, n); 
    return 0; 
} 
