// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void merge(int *arr , int start, int mid,int end){
    int size1 = mid-start +1;
    int size2 = end - mid;

    int * arr1 = new int[size1];
    int * arr2 = new int[size2];

    for (int i = 0; i<size1;i++){
        arr1[i] = arr[start + i];
    }
    for (int i = 0; i<size2;i++){
        arr2[i] = arr[mid +i+1];
    }

    int temp1 = 0;
    int temp2 = 0;
    int step = start;

    while(temp1<size1 && temp2<size2){
        if (arr1[temp1] < arr2[temp2])
            arr[step++] = arr1[temp1++];
        else
            arr[step++] = arr2[temp2++];
    }

    while(temp1!=size1){
        arr[step++] = arr1[temp1++];
    }
    while(temp2!=size2){
        arr[step++] = arr2[temp2++];
    }

    // deallocating memory
    delete[] arr1;
    delete[] arr2;
    
    return;
}

void mergeSort(int array[], int begin, int end)
{
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
    return;
}
 
void print(int A[], int size){
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}
 
int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Unsorted array is \n";
    print(arr, size);
 
    mergeSort(arr, 0, size - 1);
 
    cout << "\nSorted array is \n";
    print(arr, size);
    return 0;
}