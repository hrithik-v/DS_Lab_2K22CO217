// 17. Link list insertion and deletion at end

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

void del_end(Node *&root)
{
    if (root->next->next == NULL)
    {
        root->next = NULL;
        return;
    }

    del_end(root->next);
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

    //----- For creation of LL----
    for (int i = 1; i < 11; i++)
        insert_end(root, i);
    // ---------------------------

    print(root);

    del_end(root);
    print(root);
    
    insert_end(root,417);
    
    print(root);
    return 0;
}

