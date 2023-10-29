// 58. AVL Tree Deletion

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
Node* insert(Node* root, int val);  
void inOrderTraversal(Node* root);

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int val) {
    if (root == NULL)
        return root;

    if (val < root->val)
        root->left = deleteNode(root->left, val);
    else if (val > root->val)
        root->right = deleteNode(root->right, val);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = (root->left) ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalanceFactor(root);

    // Left-Left Case
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Left-Right Case
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right-Right Case
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Right-Left Case
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main() {
    Node* root = NULL;

    int values[] = {10, 20, 30, 25, 5};
    for (int val : values) {
        root = insert(root, val);
    }

    cout << "Inorder traversal of AVL tree: \n";
    inOrderTraversal(root);
    root = deleteNode(root,30); //  deleted 30
    cout<<endl;
    inOrderTraversal(root);
    cout << endl;

    return 0;
}

// ----------------------------------------------------------

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