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
}