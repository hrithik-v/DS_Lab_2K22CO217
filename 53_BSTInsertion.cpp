// 53. Binary search tree insertion

#include <iostream>
using namespace std;


// Tree Node
class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int X){
        data = X;
        left = NULL;
        right = NULL;
    }

};

Node* insertBST(Node * root, int X){
    if (root==NULL)
        return new Node(X);

    if (root->data >= X)
        root->left = insertBST(root->left, X);
    else
        root->right = insertBST(root->right, X);

    return root;
}

void printInorder(Node* root){
    if (root==NULL)
        return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
    return;
}

int main(){
    Node * root = NULL;

    root = insertBST(root, 5);
    root = insertBST(root, 1);
    root = insertBST(root, 4);
    root = insertBST(root, 3);
    root = insertBST(root, 2);
    root = insertBST(root, 10);
    root = insertBST(root, 8);

    printInorder(root);
}