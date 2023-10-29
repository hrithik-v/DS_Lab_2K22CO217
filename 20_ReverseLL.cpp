// 20. Linked List reversing LL

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

Node * reverseLL(Node * root){
    if (root->next == NULL){
        return root;
    }

    Node * temp = reverseLL(root->next);
    root->next->next = root;
    root->next = NULL;

    return temp;
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

    for (int i = 10; i > 0; i--){
        Node * temp = new Node(i);
        temp->next = root;
        root = temp;
    }

    print(root);
    cout<<"Reversed LL: \n";
    root = reverseLL(root);
    print(root);


}