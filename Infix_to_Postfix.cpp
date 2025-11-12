#include <bits/stdc++.h>  
using namespace std;

// A stack
#define MAX 100
char stackArr[MAX];
int top = -1;

// Function to push an element onto stack
void push(char c) {
    if (top == MAX - 1)
        cout << "Stack Overflow!" << endl;
    else
        stackArr[++top] = c;
}

// Function to pop an element from stack
char pop() {
    if (top == -1)
        return '\0';  // stack empty
    else
        return stackArr[top--];
}

// Function to check precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Function to check if character is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Main conversion function
void infixToPostfix(char infix[]) {
    char postfix[MAX];
         int j = 0; // for postfix index

    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        // If operand, add to postfix
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            postfix[j++] = c;
        }

        // If '(' push to stack
        else if (c == '(') {
            push(c);
        }

        // If ')' pop till '('
        else if (c == ')') {
            while (top != -1 && stackArr[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '(' from stack
        }

        // If operator
        else if (isOperator(c)) {
            while (top != -1 && precedence(stackArr[top]) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    // Pop all remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // end string

    cout << "Postfix Expression: " << postfix << endl;
}

// Main function
int main() {
    char infixExp[MAX];
    cout << "Enter infix expression: ";
    cin >> infixExp;

    infixToPostfix(infixExp);
    return 0;
}
