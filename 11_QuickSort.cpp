#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int arr[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[low];

    while (i < j)
    {
        while (arr[i] <= arr[low] && i <= high)
        {
            i++;
        }
        while (arr[j] > arr[low] && j >= low)
        {
            j--;
        }

        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);

    return j;
}

// Function to sort an array using quick sort algorithm.
void quickSort(int arr[], int low, int high)
{
    if (low <= high)
    {

        int pivotNo = partition(arr, low, high);
        quickSort(arr, low, pivotNo - 1);
        quickSort(arr, pivotNo + 1, high);
        return;
    }
}

int main()
{

    int arr[] = {4, 1, 3, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printArray(arr, n);
}