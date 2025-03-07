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
// Run the summation process 10 times
for (int run = 0; run < RUNS; run++) {
    sum = 0; // Reset sum for each run
    clock_t start = clock(); // Start time

    // Sequential summation
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }

    clock_t end = clock(); // End time

    // Calculate time taken in milliseconds
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    total_time += time_taken; // Add to total time

    printf("Run %d - Sum: %lld, Time taken: %.2f ms\n", run + 1, sum, time_taken);
}
// Compute average execution time
double average_time = total_time / RUNS;
printf("\nAverage execution time over %d runs: %.2f ms\n", RUNS, average_time);

free(arr); // Free allocated memory
return 0;
}



