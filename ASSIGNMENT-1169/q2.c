#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 1000000  // 1 million elements
#define RUNS 10       // Number of runs

int main() {
    int *arr = (int *)malloc(SIZE * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    long long sum;
    double total_time_static = 0.0;

    // Fill the array with 1s
    for (int i = 0; i < SIZE; i++) {
        arr[i] = 1;
    }
// Static Scheduling with Reduction
for (int run = 0; run < RUNS; run++) {
    sum = 0;
    double start_time = omp_get_wtime();

    #pragma omp parallel for reduction(+:sum) schedule(static)
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }

    double end_time = omp_get_wtime();
    double time_taken = (end_time - start_time) * 1000;
    total_time_static += time_taken;

    printf("Static - Run %d: Sum = %lld, Time = %.2f ms\n", run + 1, sum, time_taken);
}

// Print average execution time
printf("\nAverage execution time (Static): %.2f ms\n", total_time_static / RUNS);

free(arr);
return 0;
}