#include <iostream>
using namespace std;

int main()
{
    // string palindrome check

    string str;
    getline(cin, str);

    string initial = str;

    for (int i = 0; i < str.length() / 2; i++)
    {
        swap(str[i], str[str.length() - 1 - i]);
    }

    if (initial == str)
        cout << "String is Palindrome";

    else
        cout << "String NOT a Palindrome";
    return 0;
}
