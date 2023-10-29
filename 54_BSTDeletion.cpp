// 54. Deleting Element from BST

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


Node* findMin(Node* root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}

Node * deleteBST(Node * root,int X){
    if (root->data == X){
        // Case 1: Node to be deleted has 0 children
        if (root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // Case 2: Node to be deleted has 1 child
        else if (root->left == NULL && root->right != NULL){
            Node * temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL && root->left != NULL){
            Node * temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Node to be deleted has 2 children
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteBST(root->right, temp->data);
        }

    }
    else{
        if (X <= root->data)
            root->left = deleteBST(root->left, X);
        else
            root->right = deleteBST(root->right, X);
    }
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
    root = insertBST(root, 2);
    root = insertBST(root, 4);
    root = insertBST(root, 3);
    root = insertBST(root, 1);
    root = insertBST(root, 10);
    root = insertBST(root, 8);
    // --------------------

    printInorder(root);
    root = deleteBST(root, 5);
    cout<<"\nBST After deletion of 5 :\n";

    printInorder(root);
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