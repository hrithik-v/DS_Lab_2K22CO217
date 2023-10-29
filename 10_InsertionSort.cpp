#include <stdio.h>

int main(){
    int arr[] = {5, 7, 9, 14, 2, 6, 11};
    int n = sizeof(arr) / sizeof(int);

    // INSERTION SORT ALGORITHM

    for (int i = 1; i <= n - 1; i++){
        int curr = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > curr)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }

    // For printing of sorted array
    for (int i = 0; i < n; i++){
        printf("%d, ", arr[i]);
    }
}


