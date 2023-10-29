// 19. Link list searching and printing

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// To create LL
void insert_end(Node *&, int);

int search(Node *root, int X)
{
    int pos = 0;
    while (root != NULL)
    {
        if (root->data == X)
            return pos;
        pos++;

        root = root->next;
    }

    return -1;
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

    for (int i = 1; i < 11; i++)
        insert_end(root, i);
    
    print(root);
    cout << "----------" << endl;

    cout<<"5 Found at : "<<search(root, 5);
    cout<<"\n10 Found at : "<<search(root, 10);

    return 0;
}

// --------------------------------------------------------------------------- 

void insert_end(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return;
    }
    insert_end(root->next, data);
    return;
}
