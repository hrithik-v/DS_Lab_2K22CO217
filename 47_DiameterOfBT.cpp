// 47. Diameter of binary tree

#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

// ----------Utility Fn(s)-----------
Node* newNode(int);
Node* buildTree(string);
// ----------------------------------


int calculateDiameter(Node *node, int &diameter)
{
    if (node == NULL)
        return 0;

    int leftHeight = calculateDiameter(node->left, diameter);
    int rightHeight = calculateDiameter(node->right, diameter);

    // Update the diameter if a longer path is found
    diameter = max(diameter, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(Node *root)
{
    int diameter = 0;
    calculateDiameter(root, diameter);
    return diameter;
}
int main()
{

    string s;
    getline(cin,s);
    Node* root = buildTree(s);
    
    cout << "Diameter of the binary tree: " << diameterOfBinaryTree(root);
    
    return 0;
}

// --------------------------------------------------------------------------------

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;

}

Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
