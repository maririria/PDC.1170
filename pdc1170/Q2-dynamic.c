#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 1000000
#define NUM_THREADS 4

int main(){
    int *arr = (int *)malloc(SIZE * sizeof(int));
    if (arr == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i<SIZE; i++){
        arr[i] = 1;
    }
    long long totalSum = 0;
    double totalTime = 0.0;

    omp_set_num_threads(NUM_THREADS);

    
}