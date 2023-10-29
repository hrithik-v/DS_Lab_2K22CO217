// 26. Merge two sorted link list

#include <iostream>
using namespace std;
// Issue in Algo

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

Node* merge2sort(Node* r1, Node* r2) {
    Node* root = new Node(-1);  // Create a dummy node for the merged list
    Node* temp = root;

    while (r1 != NULL && r2 != NULL) {
        Node* t = NULL;
        if (r1->data < r2->data) {
            t = new Node(r1->data);
            r1 = r1->next;
        } else {
            t = new Node(r2->data);
            r2 = r2->next;
        }

        temp->next = t;  // Connect the new node to the merged list
        temp = temp->next;  // Move temp to the newly added node
    }

    // Append the remaining nodes from r1 and r2 (if any)
    while (r1 != NULL) {
        Node* t = new Node(r1->data);
        temp->next = t;
        temp = temp->next;
        r1 = r1->next;
    }

    while (r2 != NULL) {
        Node* t = new Node(r2->data);
        temp->next = t;
        temp = temp->next;
        r2 = r2->next;
    }

    return root->next;  // Skip the dummy node and return the merged list
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
    Node *h1 = NULL;
    Node *h2 = NULL;

    // Sample LL
    for (int i = 10; i > 0; i--)
    {
        Node *temp = new Node(i);
        temp->next = h1;
        h1 = temp;
    }
    for (int i = 20; i > 0; i = i - 2)
    {
        Node *temp = new Node(i);
        temp->next = h2;
        h2 = temp;
    }

    print(h1);
    cout << "-----\n";
    print(h2);

    h1 = merge2sort(h1, h2);

    cout << "Merged Sorted LL:-\n";
    print(h1);
}