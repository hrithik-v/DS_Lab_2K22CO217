// 39. First negative integer in every window of size k

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> findFirstNegativeInWindow(const vector<int>& arr, int k) {
    vector<int> result;
    deque<int> negIndices;

    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            negIndices.push_back(i);
        }
    }

    for (int i = k; i < arr.size(); i++) {
        if (!negIndices.empty()) {
            result.push_back(arr[negIndices.front()]);
        } else {
            result.push_back(0);
        }

        while (!negIndices.empty() && negIndices.front() <= i - k) {
            negIndices.pop_front();
        }

        if (arr[i] < 0) {
            negIndices.push_back(i);
        }
    }

    if (!negIndices.empty()) {
        result.push_back(arr[negIndices.front()]);
    } else {
        result.push_back(0);
    }

    return result;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> result = findFirstNegativeInWindow(arr, k);

    cout << "First Negative Integers in Windows of Size " << k << ":" << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
