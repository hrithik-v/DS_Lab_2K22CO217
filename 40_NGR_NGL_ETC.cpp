// 40. Next greater to right, next greater to left, nearest smaller to left, next smaller to right

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to find the Next Greater Element to the Right (NGR)
vector<int> nextGreaterRight(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] > arr[s.top()]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

// Function to find the Next Greater Element to the Left (NGL)
vector<int> nextGreaterLeft(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[i] > arr[s.top()]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

// Function to find the Nearest Smaller Element to the Left (NSL)
vector<int> nearestSmallerLeft(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] < arr[s.top()]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = arr[s.top()];
        }
        s.push(i);
    }

    return result;
}

// Function to find the Next Smaller Element to the Right (NSR)
vector<int> nextSmallerRight(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[i] < arr[s.top()]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = arr[s.top()];
        }
        s.push(i);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};

    vector<int> ngr = nextGreaterRight(arr);
    vector<int> ngl = nextGreaterLeft(arr);
    vector<int> nsl = nearestSmallerLeft(arr);
    vector<int> nsr = nextSmallerRight(arr);

    cout << "Next Greater to Right: ";
    for (int value : ngr) {
        cout << value << " ";
    }
    cout << endl;

    cout << "Next Greater to Left: ";
    for (int value : ngl) {
        cout << value << " ";
    }
    cout << endl;

    cout << "Nearest Smaller to Left: ";
    for (int value : nsl) {
        cout << value << " ";
    }
    cout << endl;

    cout << "Next Smaller to Right: ";
    for (int value : nsr) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
