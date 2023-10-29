// 18. Link list insertion and deletion at a position 

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

// To create LL
void insert_end(Node *&, int);


Node *insert_at(Node *root, int X, int pos)
{
    if (pos == 0 || root == NULL)
    {
        Node *temp = new Node(X);
        temp->next = root;
        return temp;
    }

    root->next = insert_at(root->next, X, pos - 1);

    return root;
}

Node *delete_at(Node *root, int pos)
{
    if (pos == 0){
        Node * temp = root->next;
        delete root;       // free up memory

        return temp;
    }

    root->next = delete_at(root->next, pos - 1);

    return root;
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

    root = insert_at(root, 32, 0);      // insert at index 0
    print(root);

    root = delete_at(root,1);           // delete at index 1
    print(root);

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
