// 60. Binary Expression Tree

#include <bits/stdc++.h>
#include <stack>
#include <string>
using namespace std;

// Binary Expression Tree Node
class Node {
    public: 
    string data;
    Node* left;
    Node* right;

    Node(string val) : data(val), left(NULL), right(NULL) {}
};

// Function to check if a string is an operator
bool isOperator(const string& str) {
    return (str == "+" || str == "-" || str == "*" || str == "/");
}

// Function to create a binary expression tree from a postfix expression
Node* createExpressionTree(const string& postfix) {
    stack<Node*> st;
    istringstream iss(postfix);
    string token;

    while (iss >> token) {
        Node* node = new Node(token);
        if (isOperator(token)) {
            node->right = st.top();
            st.pop();
            node->left = st.top();
            st.pop();
        }
        st.push(node);
    }

    return st.top();
}

// Function to evaluate a binary expression tree
int evaluateExpressionTree(Node* root) {
    if (root == NULL) {
        return 0;
    }

    if (!isOperator(root->data)) {
        return stoi(root->data);
    }

    int leftVal = evaluateExpressionTree(root->left);
    int rightVal = evaluateExpressionTree(root->right);

    if (root->data == "+") {
        return leftVal + rightVal;
    } else if (root->data == "-") {
        return leftVal - rightVal;
    } else if (root->data == "*") {
        return leftVal * rightVal;
    } else if (root->data == "/") {
        return leftVal / rightVal;
    }

    return 0; // Default case (should not be reached)
}

// Function to perform an in-order traversal of the binary expression tree
void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    if (isOperator(root->data)) {
        cout << "(";
    }

    inOrderTraversal(root->left);
    cout << root->data;
    inOrderTraversal(root->right);

    if (isOperator(root->data)) {
        cout << ")";
    }
}

int main() {
    string postfixExpression = "3 4 + 2 1 - * 5 /"; // Example postfix expression
    Node* expressionTree = createExpressionTree(postfixExpression);

    cout << "Infix Expression: ";
    inOrderTraversal(expressionTree);
    cout << endl;

    int result = evaluateExpressionTree(expressionTree);
    cout << "Result of the Expression: " << result << endl;

    return 0;
}
