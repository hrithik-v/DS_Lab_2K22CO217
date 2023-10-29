// 25. Find middle element of link list in o(n) time

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};


void middleLL(Node *root)
{
    int size = 0;
    Node *temp = root;
    // calculating size
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }

    temp = root;

    for (int i = 0; i < size / 2; i++)
    {
        temp = temp->next;
    }

    cout << "Middle Element: " << temp->data << endl;
    return;
}

void print(Node *root)
{
    if (root == NULL)
    {
        cout << endl;
        return;
    }
    cout << root->data << " ";
    print(root->next);

    return;
}

int main()
{
    Node *root = NULL;

    for (int i = 10; i > 0; i--)
    {
        Node * temp = new Node(i);
        temp->next = root;
        root = temp;
    }

    middleLL(root);

}