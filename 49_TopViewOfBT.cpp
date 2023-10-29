// 49. Top view of binary tree

#include <bits/stdc++.h>
#include <queue>
using namespace std;

// Tree Node
class Node
{
    public:
    int data;
    Node* left;
    Node* right;

};

// ----------Utility Fn(s)-----------
Node* newNode(int);
Node* buildTree(string);
// ----------------------------------

void topView(Node* root) {
    if (root == NULL) {
        return;
    }

    map<int, int> topViewMap;  // Store the top view nodes at each vertical level.
    queue<pair<Node*, int>> q;  // Queue for level-order traversal with horizontal distance.

    q.push({root, 0});

    while (!q.empty()) {
        Node* current = q.front().first;
        int hd = q.front().second;
        q.pop();

        // If the current horizontal distance (hd) is not in the map, add it to the map.
        if (topViewMap.find(hd) == topViewMap.end()) {
            topViewMap[hd] = current->data;
        }

        // Enqueue the left and right children with updated horizontal distances.
        if (current->left) {
            q.push({current->left, hd - 1});
        }
        if (current->right) {
            q.push({current->right, hd + 1});
        }
    }

    // Print the top view of the binary tree.
    for (const auto& pair : topViewMap) {
        cout << pair.second << " ";
    }
    cout << endl;
}

int main() {
    string s;
    getline(cin,s);
    Node* root = buildTree(s);
    
    cout<<"\nTop View of Binary Tree: ";
    topView(root);

    return 0;
}

// ================================================================================================

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
