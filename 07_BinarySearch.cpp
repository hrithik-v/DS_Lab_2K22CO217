// 7. Binary Search using switch case

#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int no){
    // for non-existence no. 
    if(start>end){
        return -1;
    }
    
    int mid = (start+end)/2;
    int index;
    if(arr[mid] == no)
        return mid;
    else if(no < arr[mid])
        index = binarySearch(arr, start, mid-1, no);
    else    
        index = binarySearch(arr, mid+1, end, no);

    return index;
}

int main(){
    // sorted array
    int arr[] = {2,3,5,9,12,15};
    int length = sizeof(arr)/sizeof(int);

    // I/P for value to be searched.
    int n;
    printf("Enter No. : ");
    scanf("%d", &n);


    printf("Found at: %d", binarySearch(arr, 0, length-1, n));

}