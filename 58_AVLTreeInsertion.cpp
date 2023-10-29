// 58. AVL Tree Insertion 

#include <iostream>
using namespace std;
#include <algorithm>

class Node {
    public:
    int val;
    Node* left;
    Node* right;
    int height;

    Node(int x) : val(x), left(NULL), right(NULL), height(1) {}
};

int getHeight(Node* node) {
    return (node != NULL) ? node->height : 0;
}

int getBalanceFactor(Node* node);

Node* rightRotate(Node* y);
Node* leftRotate(Node* x);

// For Creation of AVL Tree
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalanceFactor(root);

    if (balance > 1) {
        if (val < root->left->val)
            return rightRotate(root);
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    if (balance < -1) {
        if (val > root->right->val)
            return leftRotate(root);
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    return root;
}



void inOrderTraversal(Node* root);


int main() {
    Node* root = NULL;

    int values[] = {10, 20, 30, 25, 5, 19, 12, 32};
    for (int val : values) {
        root = insert(root, val);
    }

    cout << "Inorder traversal of AVL tree: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}

// ----------------------------------------------------------



void inOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    return y;
}

int getBalanceFactor(Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}