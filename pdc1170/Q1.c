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
    