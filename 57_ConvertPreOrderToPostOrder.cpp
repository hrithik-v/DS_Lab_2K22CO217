// 57. Converting Pre Order to Post Order

#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Node
{
    public:
    int val;
    Node *left;
    Node *right;
    Node(int value) : val(value), left(NULL), right(NULL) {}
};

Node *buildTreeFromPreorder(vector<int> &preorder, int &index, int maxValue)
{
    if (index >= preorder.size() || preorder[index] >= maxValue)
    {
        return NULL;
    }

    Node *root = new Node(preorder[index++]);
    root->left = buildTreeFromPreorder(preorder, index, root->val);
    root->right = buildTreeFromPreorder(preorder, index, maxValue);
    return root;
}

void postorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}

int main()
{
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    int n = 0;
    int maxValue = INT_MAX;

    Node *root = buildTreeFromPreorder(preorder, n, maxValue);

    cout<<"PostOrder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}