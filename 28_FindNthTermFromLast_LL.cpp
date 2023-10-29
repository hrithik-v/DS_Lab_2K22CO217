// 28. Program to find Nth node from the end of a linked list

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

int getNthFromLast(Node *head, int n)
{
    int ctr = 0;
    Node * temp = head;
    
    while(head!=NULL){
        if (ctr!=n){
            ctr++;
        }else
            temp = temp->next;
        head = head->next;
    }
    
    if (ctr!=n)
        return -1;
    return temp->data;
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

    print(root);

    cout<<"2nd Node from last: "<<getNthFromLast(root,2)<<endl;
    cout<<"5th Node from last: "<<getNthFromLast(root,5);
}