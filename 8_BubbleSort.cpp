#include <stdio.h>

int main(){
    int arr[] = {9,5,4,3,2,1};
    int size = sizeof(arr)/sizeof(int);

    
    for (int i = 1; i <= size-1; i++){
        for (int j = 0; j < size-i ; j++){

            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted Array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
}

