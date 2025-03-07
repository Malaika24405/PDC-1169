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
