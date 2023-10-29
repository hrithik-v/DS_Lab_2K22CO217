// 35. Prefix Representation

#include <iostream>
#include <stack>
#include <string>
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

// Function to convert an infix expression to prefix notation
string infixToPrefix(string infix) {
    stack<char> operatorStack;
    stack<string> operandStack;
    string prefix = "";

    for (int i = 0; i < infix.length(); i++) {
        char currentChar = infix[i];

        if (currentChar == ' ') {
            continue;  // Ignore spaces
        } else if (isalnum(currentChar)) {
            // Operand, so add it to the operand stack
            string operand = "";
            while (i < infix.length() && isalnum(infix[i])) {
                operand += infix[i];
                i++;
            }
            i--;  // Move back to the last alphanumeric character
            operandStack.push(operand);
        } else if (currentChar == '(') {
            operatorStack.push(currentChar);
        } else if (currentChar == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                string operand2 = operandStack.top();
                operandStack.pop();
                string operand1 = operandStack.top();
                operandStack.pop();
                char op = operatorStack.top();
                operatorStack.pop();
                string newOperand = op + operand1 + operand2;
                operandStack.push(newOperand);
            }
            operatorStack.pop();  // Pop the '('
        } else if (isOperator(currentChar)) {
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(currentChar)) {
                string operand2 = operandStack.top();
                operandStack.pop();
                string operand1 = operandStack.top();
                operandStack.pop();
                char op = operatorStack.top();
                operatorStack.pop();
                string newOperand = op + operand1 + operand2;
                operandStack.push(newOperand);
            }
            operatorStack.push(currentChar);
        }
    }

    // Process remaining operators
    while (!operatorStack.empty()) {
        string operand2 = operandStack.top();
        operandStack.pop();
        string operand1 = operandStack.top();
        operandStack.pop();
        char op = operatorStack.top();
        operatorStack.pop();
        string newOperand = op + operand1 + operand2;
        operandStack.push(newOperand);
    }

    if (!operandStack.empty()) {
        prefix = operandStack.top();
    }

    return prefix;
}

int main() {
    string infixExpression = "3 + 4 * ( 2 - 1 ) / 5";
    string prefixExpression = infixToPrefix(infixExpression);

    cout << "Infix Expression: " << infixExpression << endl;
    cout << "Prefix Expression: " << prefixExpression << endl;

    return 0;
}
