#include <iostream>
using namespace std;

int main()
{

    int end = -1;
    int size = 5; // Assumed
    int arr[size];

    while (true)
    {
        int choice;
        cout << "\n1. Insert\n2. Delete\n3. Print\n0. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (end >= size - 1)
            {
                cout << "Overflow";
                continue;
            }
            
            int e;
            cout << "Value: ";
            cin >> e;

            arr[++end] = e;
        }
        else if (choice == 2)
        {
            if (end == -1){
                cout<<"Array Underflow\n";
                continue;
            }
            int X;
            cout << "Element to be deleted: ";
            cin >> X;

            bool found = false;
            for (int i = 0; i <= end; i++)
            {
                if (!found)
                {
                    if (arr[i] == X)
                    {
                        found = true;
                        i--;
                    }
                }
                else
                {
                    arr[i] = arr[i + 1];
                }
            }
            end--;
        }
        else if (choice == 3)
        {   cout<<endl;
            for (int t = 0; t <= end; t++)
            {
                cout << arr[t] << " ";
            }
        }
        else
        {
            break;
        }
    }

    return 0;
}