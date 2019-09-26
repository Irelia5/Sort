#include "sort.h"
#include <stdio.h>

#define swap(x, y) { int temp = x; x = y; y = temp; }

void printArray(int * array, int length)
{
    for(int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

//直接插入排序
void InsertSort(int * a, int length)
{
    int temp, i, j;
    for(i = 1; i < length; i++){
        temp = a[i];
        for(j = i - 1; j >= 0 && temp < a[j]; j--){
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}

//希尔排序
//希尔排序是直接插入排序的变体，步长改变
void ShellSort(int *a, int length)
{
    int i, j, temp;
    int gap;//gap是步长
    for(gap = length >> 1; gap > 0; gap >>= 1){
        for(i = gap; i < length; i += gap){
            temp = a[i];
            for(j = i - gap; j >= 0 && temp < a[j]; j -= gap){
                a[j + gap] = a[j];
            }
            a[j + gap] = temp;
        }
    }
}

//冒泡排序
void BubbleSort(int * a, int length)
{
    int flag;
    for(int i = length - 1; i > 0; i--){
        flag = 1;
        for(int j = 0; j < i; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                flag = 0;
            }
        }
        if(1 == flag)
            break;
    }
}

int partition(int *a ,int left,int right)
{
    int i, j;
    for(i = j = left; i < right; i++){
        if(a[i] < a[right]){
            swap(a[i], a[j]);
            j++;
        }
    }
    swap(a[j], a[right]);
    return j;
}

void QuickSort(int *a, int left, int right)
{
    int pivot;//切分点
    if(left < right){
        pivot = partition(a, left, right);
        QuickSort(a, left, pivot - 1);
        QuickSort(a, pivot + 1, right);
    }
}

void SelectSort(int * a, int length)
{
    for(int i = 0; i < length - 1; i++){
        int MinPos = i;
        for(int j = i + 1; j < length; j++){
            if(a[j] < a[MinPos]){
                MinPos = j;
            }
        }
        if(MinPos != i){
            swap(a[MinPos], a[i]);
        }
    }
}

void adjustHeap(int *array, int start, int length)
{
    int dad = start;
    int son = 2 * dad + 1;
    while(son < length){
        if(son + 1 < length && array[son + 1] > array[son]){
            son++;
        }
        if(array[dad] >= array[son]){
            return;
        }else{
            swap(array[dad], array[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void BuildMaxHeap(int * array, int length)
{
    for(int i = length / 2 - 1; i >= 0; i--){
        adjustHeap(array, i, length);
    }
}

void HeapSort(int * array, int length)
{
    BuildMaxHeap(array, length);
    for(int i = length - 1; i > 0; i--){
        swap(array[i], array[0]);
        adjustHeap(array, 0, i - 1);
    }
}

void CountSort(int * array,int length)
{
    int count[100] = {0};
    for(int i = 0; i < length; i++){
        count[array[i]]++;
    }
    int k = 0;
    for(int j = 0; j < 100; j++){
        for(int i = 0; i < count[j]; i++){
            array[k++] = j;
        }
    }
}
