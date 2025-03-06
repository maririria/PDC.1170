#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int *arr = (int *)malloc(SIZE * sizeof(int)); 
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < SIZE; i++) {
        arr[i] = 1;
    }

    long long totalSum = 0;
    double totalTime = 0.0;

    for (int run = 0; run < 10; run++) {
        totalSum = 0; 
        clock_t start = clock(); 

        for (int i = 0; i < SIZE; i++) {
            totalSum += arr[i]; 
        }

        clock_t end = clock(); 
        double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        totalTime += timeTaken;

        printf("Run %d: Sum = %lld, Time Taken = %f seconds\n", run + 1, totalSum, timeTaken);
    }

printf("\nAverage Execution Time: %f seconds\n", totalTime / 10);

free(arr);
return 0;
}