// 21. Merge point of two given link list

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


void merge2LL(Node* root1, Node* root2){
    while (root1->next != NULL){
        root1 = root1->next;
    }

    root1->next = root2;

    return ;
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
    Node *root1 = NULL;

    for (int i = 10; i > 0; i--){
        Node * temp = new Node(i);
        temp->next = root1;
        root1 = temp;
    }

    Node *root2 = NULL;

    for (int i = 20; i > 0; i=i-2){
        Node * temp = new Node(i);
        temp->next = root2;
        root2 = temp;
    }



    cout<<"LL 1: \n";
    print(root1);
    cout<<"LL 2: \n";
    print(root2);

    cout<<"Merged LL: \n";
    merge2LL(root1, root2);

    print(root1);
}