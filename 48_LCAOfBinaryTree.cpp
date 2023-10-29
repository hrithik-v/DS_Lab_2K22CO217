// 48. Lowest common ancestor 

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

Node* findLCA(Node* root, int p, int q) {
    if (root == NULL) {
        return NULL;
    }

    // If either p or q matches the current node's value, it is the LCA.
    if (root->data == p || root->data == q) {
        return root;
    }
    // Recursively search for p and q in the left and right subtrees.
    Node* leftLCA = findLCA(root->left, p, q);
    Node* rightLCA = findLCA(root->right, p, q);

    // If both left and right LCA are not NULL, the current node is the LCA.
    if (leftLCA && rightLCA) {
        return root;
    }
    // If one of the LCA nodes is NULL, return the other non-NULL LCA.
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main()
{

    string s;
    getline(cin,s);
    Node* root = buildTree(s);
    
    cout << "LCA of 5 & 9: " << findLCA(root, 5, 9)->data;
    
    return 0;
}

// --------------------------------------------------------------------------------

Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
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

        // Get the current node's dataue from the string
        string currdata = ip[i];

        // If the left child is not null
        if(currdata != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currdata));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currdata = ip[i];

        // If the right child is not null
        if(currdata != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currdata));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
