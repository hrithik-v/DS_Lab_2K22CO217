#include <iostream>
using namespace std;


int main(){
    int arr[] = {5, 4, 10, 1, 2, 3, 11, 7};
    int size = sizeof(arr)/sizeof(int);

    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[i] > arr[j]){
                swap(arr[i],arr[j]);
            }
        }
        
    }

    // print
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    

}