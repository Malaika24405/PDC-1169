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
    
    for (int run = 0; run < RUNS; run++) {
        sum = 0;
        double start_time = omp_get_wtime();

        // Parallel summation using dynamic scheduling with reduction
        #pragma omp parallel for reduction(+:sum) schedule(dynamic, 1000)
        for (int i = 0; i < SIZE; i++) {
            sum += arr[i];
        }

        double end_time = omp_get_wtime();
        double time_taken = (end_time - start_time) * 1000;
        total_time_dynamic += time_taken;

        printf("Dynamic - Run %d: Sum = %lld, Time = %.2f ms\n", run + 1, sum, time_taken);
    }
    // Compute and display average execution time over multiple runs
    printf("\nAverage execution time (Dynamic): %.2f ms\n", total_time_dynamic / RUNS);

    // Free allocated memory
    free(arr);
    return 0;
}