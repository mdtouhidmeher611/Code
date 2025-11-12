#include <iostream>
using namespace std;

//creating a stack
#define MAX 5   
int stackArr[MAX];
int top = -1;  

// Function to push an element
void push(int item) {
    if (top == MAX - 1) {
        cout << "Stack Overflow!" << endl;
    } else {
        top++;
        stackArr[top] = item;
        cout << item << " pushed into stack." << endl;
    }
}

// Function to pop an element
void pop() {
    if (top == -1) {
        cout << "Stack Underflow!" << endl;
    } else {
        cout << stackArr[top] << " popped from stack." << endl;
        top--;
    }
}

// Function to display top element
void peek() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Top element is: " << stackArr[top] << endl;
    }
}

// Function to display all elements
void display() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--) {
            cout << stackArr[i] << " ";
        }
        cout << endl;
    }
}

// Main function
int main() {
    int choice, value;

    while (true) {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
}
