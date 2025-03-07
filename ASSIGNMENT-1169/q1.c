#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000   // 1 million elements
#define RUNS 10        // Number of runs

int main() {
    int *arr = (int *)malloc(SIZE * sizeof(int)); // Dynamically allocate array

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    long long sum;
    double total_time = 0.0; // To store total execution time

    // Fill the array with 1s
    for (int i = 0; i < SIZE; i++) {
        arr[i] = 1;
    }

