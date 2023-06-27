#include <stdlib.h>
#include <stdio.h>

void swap(int array[], int index1, int index2);
int partition(int array[], int low, int high);
void quickSort(int array[], int low, int high);

int main(void)
{
    int array[5] = {4, 3, 2, 0, -1};
    int i;

    quickSort(array, 0, 4);

    for(i = 0; i < 5; i++)
        printf("%d ", array[i]);

    return 0;
}

void quickSort(int array[], int low, int high)
{
    int pivotIndex;

    if(low < high) 
    {
        pivotIndex = partition(array, low, high);
        quickSort(array, low, pivotIndex-1);
        quickSort(array, pivotIndex+1, high);
    }
}

int partition(int array[], int low, int high)
{
    int pivot, pivotIndex, i;

    swap(array, low, (low+high)/2);

    pivot = array[low];
    pivotIndex = low;

    for(i = low+1; i <= high; i++)
        if(array[i] < pivot)
            swap(array, ++pivotIndex, i);

    swap(array, low, pivotIndex);

    return pivotIndex;
}

void swap(int array[], int index1, int index2)
{
    int temp = array[index1];

    array[index1] = array[index2];
    array[index2] = temp;
}