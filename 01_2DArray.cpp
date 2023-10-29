#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "No. of Students: ";
    cin >> n;

    int arr[n][5];

    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << endl;
        for (int j = 0; j < 5; j++) {
            int marks;
            cout << "Sub " << j + 1 << ": ";
            cin >> marks;
            arr[i][j] = marks;
        }
    }

    // Array to store total marks for each subject
    int total_subject_marks[5] = {0};

    for (int i = 0; i < n; i++) {
        int total = 0;
        for (int j = 0; j < 5; j++) {
            total += arr[i][j];
            total_subject_marks[j] += arr[i][j];
        }
        cout << "\nStudent " << i + 1 << endl;
        cout << "Total: " << total << endl;
    }

    cout << "\nAverage" << endl;
    for (int p = 0; p < 5; p++) {
        float subject_avg = static_cast<float>(total_subject_marks[p]) / n;
        cout << "Sub " << p + 1 << ": " << subject_avg << endl;
    }

    return 0;
}
