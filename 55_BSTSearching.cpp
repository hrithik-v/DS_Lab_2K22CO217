// 55. Searching in a binary search tree

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

Node* insertBST(Node *,int);

bool searchBST(Node* root, int X) {
    if (root == NULL) {
        return false; // Value not found in the BST
    }

    if (root->data == X) {
        return true; // Value found in the current node
    }

    if (X < root->data) {
        return searchBST(root->left, X); // Recursively search the left subtree
    } 
    else {
        return searchBST(root->right, X); // Recursively search the right subtree
    }
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
    root = insertBST(root, 2);
    root = insertBST(root, 4);
    root = insertBST(root, 3);
    root = insertBST(root, 1);
    root = insertBST(root, 10);
    root = insertBST(root, 8);
    // --------------------

    printInorder(root);
    cout<<endl;
    
    if (searchBST(root,10))
        cout<<"10 Found";
    else    
        cout<<"Not Found";
}

// --------------------------------------------------------------

Node* insertBST(Node * root, int X){
    if (root==NULL)
        return new Node(X);

    if (root->data >= X)
        root->left = insertBST(root->left, X);
    else
        root->right = insertBST(root->right, X);

    return root;
}