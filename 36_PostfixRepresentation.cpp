// 36. Postfix Representation

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to determine the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;  // Lower precedence for non-operators
}

// Function to convert an infix expression to postfix notation
string infixToPostfix(string infix) {
    stack<char> operatorStack;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char currentChar = infix[i];

        if (currentChar == ' ') {
            continue;  // Ignore spaces
        } else if (isalnum(currentChar)) {
            // Operand, so add it to the postfix expression
            while (i < infix.length() && (isalnum(infix[i]) || infix[i] == ' ')) {
                if (isalnum(infix[i])) {
                    postfix += infix[i];
                }
                i++;
            }
            i--;  // Move back to the last alphanumeric character
            postfix += " ";
        } else if (currentChar == '(') {
            operatorStack.push(currentChar);
        } else if (currentChar == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                postfix += " ";
                operatorStack.pop();
            }
            operatorStack.pop();  // Pop the '('
        } else if (isOperator(currentChar)) {
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(currentChar)) {
                postfix += operatorStack.top();
                postfix += " ";
                operatorStack.pop();
            }
            operatorStack.push(currentChar);
        }
    }

    // Process remaining operators
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        postfix += " ";
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    string infixExpression = "3 + 4 * ( 2 - 1 ) / 5";
    string postfixExpression = infixToPostfix(infixExpression);

    cout << "Infix Expression: " << infixExpression << endl;
    cout << "Postfix Expression: " << postfixExpression << endl;

    return 0;
}
