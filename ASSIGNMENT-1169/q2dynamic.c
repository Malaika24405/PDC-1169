#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 1000000  // 1 million elements
#define RUNS 10       // Number of runs

int main() {
    
    // Allocate memory for the array
    int *arr = (int *)malloc(SIZE * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Fill the array with 1s
    for (int i = 0; i < SIZE; i++) {
        arr[i] = 1;
    }

    long long sum;
    double total_time_dynamic = 0.0;
