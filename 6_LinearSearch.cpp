// 6. Linear Search
#include <iostream>
using namespace std;


int LinearSearch(int X, int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == X)
        {
            return 1;
        }
    }
    return 0;
}



int main()
{
    int arr[] = {1, 2, 3};

    if (LinearSearch(2, arr, sizeof(arr) / sizeof(int))){
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }
    
}