#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 1000000
#define NUM_THREADS 4

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

    omp_set_num_threads(NUM_THREADS);

    
    for (int run = 0; run < 10; run++) {
        totalSum = 0;
        double start = omp_get_wtime(); 

        #pragma omp parallel 
        {
            long long localSum = 0; 

            #pragma omp for schedule(static)
            for (int i = 0; i < SIZE; i++) {
                localSum += arr[i];
            }

            #pragma omp critical
            {
                totalSum += localSum;
            }
        }

        double end = omp_get_wtime(); 
        double timeTaken = end - start;
        totalTime += timeTaken;

        printf("Static Run %d: Sum = %lld, Time = %f seconds\n", run + 1, totalSum, timeTaken);
    }

    printf("\nAverage Execution Time (Static Scheduling with Critical Section): %f seconds\n", totalTime / 10);

        }
