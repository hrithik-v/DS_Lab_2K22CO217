// 4. Insert & Delete at Beginning

#include <iostream>
using namespace std;

const int MAX_SIZE = 5;  // Define a maximum size for the array.

void insertFront(int* arr, int& n, int& last, int X) {
    if (n >= MAX_SIZE) {
        cout << "Overflow: Array is full, cannot insert " << X << endl;
        return;
    }

    for (int i = last; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }

    arr[0] = X;
    n++;  // Increment the size of the array.
    last++;  // Update the last index.
}

void deleteFront(int* arr, int& n, int& last) {
    if (n <= 0) {
        cout << "Underflow: Array is empty, cannot delete." << endl;
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;  // Decrement the size of the array.
    last--;  // Update the last index.
}

void print_arr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[MAX_SIZE] = {9, 5, 1, 7, 4};
    int size = 5;  // Current size of the array
    int last = size - 1;  // Index of the last element

    print_arr(arr, size);
    insertFront(arr, size, last, 56);
    print_arr(arr, size);
    deleteFront(arr, size, last);
    print_arr(arr, size);

    return 0;
}
