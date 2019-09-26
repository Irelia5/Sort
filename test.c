#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

int main()
{
    time_t start, end;
    srand(time(NULL));
    int * array = (int *)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++){
        array[i] = rand()%100;
    }

    start = time(NULL);
    //各大排序算法比较 
    //InsertSort(array, N);
    //ShellSort(array, N);
    //BubbleSort(array, N);
    //QuickSort(array, 0, N - 1);
    //SelectSort(array, N);
    //HeapSort(array, N);
    CountSort(array, N);
    printArray(array, N);
    end = time(NULL);
    printf("used time is %ld\n", end - start);
    return 0;
}

