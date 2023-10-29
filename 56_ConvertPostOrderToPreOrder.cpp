// 56. Converting PostOrder to PreOrder

#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode *buildTreeFromPostorder(vector<int> &postorder, int &index, int minValue)
{
    if (index < 0 || postorder[index] <= minValue)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(postorder[index--]);
    root->right = buildTreeFromPostorder(postorder, index, root->val);
    root->left = buildTreeFromPostorder(postorder, index, minValue);
    return root;
}

void preorderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    vector<int> postorder =  {8, 5, 1, 7, 10, 9, 12};
    int n = postorder.size() - 1;
    int index = n;

    TreeNode *root = buildTreeFromPostorder(postorder, index, INT_MIN);

    cout<<"PreOrder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}