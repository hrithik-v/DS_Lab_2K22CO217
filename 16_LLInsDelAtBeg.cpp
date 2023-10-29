// 16. Linked list insertion and deletion at beginning

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

void insert_start(Node *&root, int data)
{
    Node *temp = new Node(data);
    temp->next = root;

    root = temp;

    return;
}


void del_start(Node *&root)
{
    Node *temp = root;
    root = temp->next;

    delete temp;    //  to deallocate memory of Old Head Node
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

Node* insert_end(Node*, int);

int main()
{
    Node *root = NULL;

    //----- For creation of LL----
    for (int i = 1; i < 11; i++)
        root = insert_end(root, i);
    // ---------------------------

    print(root);
    cout << "----------" << endl;
    insert_start(root, 120);
    insert_start(root, 69);

    print(root);
    // -----------------
    del_start(root);
    print(root);

    return 0;
}

Node* insert_end(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    root->next = insert_end(root->next, data);
    return root;
}