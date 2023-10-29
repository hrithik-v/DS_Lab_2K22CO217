// 14. Floor, ceil, peak, minimum in sorted rotated array

#include <iostream>
#include <vector>

using namespace std;

// Function to find the floor of a target element in a rotated sorted array
int findFloor(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int floor = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return nums[mid];
        }
        else if (nums[mid] < target) {
            floor = nums[mid];
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return floor;
}

// Function to find the ceiling of a target element in a rotated sorted array
int findCeiling(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int ceiling = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return nums[mid];
        }
        else if (nums[mid] > target) {
            ceiling = nums[mid];
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return ceiling;
}

// Function to find the peak element in a rotated sorted array
int findPeak(const vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[mid + 1]) {
            return nums[mid];
        }
        else if (nums[mid] < nums[right]) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    return nums[left];
}

// Function to find the minimum element in a rotated sorted array
int findMinimum(const vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return nums[left];
}

int main() {
    vector<int> rotatedArray = {4, 5, 6, 7, 0, 1, 2};
    int target = 3;

    int floor = findFloor(rotatedArray, target);
    int ceiling = findCeiling(rotatedArray, target);
    int peak = findPeak(rotatedArray);
    int minimum = findMinimum(rotatedArray);

    cout << "Floor of " << target << ": " << floor << endl;
    cout << "Ceiling of " << target << ": " << ceiling << endl;
    cout << "Peak element: " << peak << endl;
    cout << "Minimum element: " << minimum << endl;

    return 0;
}
