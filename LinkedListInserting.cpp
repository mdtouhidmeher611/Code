#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    cout << "\nCurrent Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Insert at the beginning
void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

// Insert at the end
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (head == nullptr) { // empty list
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

// Insert after a specific value
void insertAfter(Node* head, int value, int newData) {
    Node* temp = head;
    while (temp != nullptr && temp->data != value)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Value " << value << " not found in the list.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = temp->next;
    temp->next = newNode;
}

//  Insert at a specific position
void insertAtPosition(Node*& head, int position, int newData) {
    if (position < 1) {
        cout << "Invalid position! Position must be >= 1.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = newData;

    // Insert at the beginning
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position " << position << " is out of range.\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {
    Node* head = nullptr;
    int choice, data, value, position;

    cout << "=== Linked List Insertion Menu ===\n";

    do {
        cout << "\n1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Specific Value\n";
        cout << "4. Insert at a Specific Position\n"; 
        cout << "5. Display List\n";
        cout << "6. Close Program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> data;
                insertAtBeginning(head, data);
                break;

            case 2:
                cout << "Enter value to insert at end: ";
                cin >> data;
                insertAtEnd(head, data);
                break;

            case 3:
                cout << "Enter existing value to insert after: ";
                cin >> value;
                cout << "Enter new value to insert: ";
                cin >> data;
                insertAfter(head, value, data);
                break;

            case 4:
                cout << "Enter position to insert at: ";
                cin >> position;
                cout << "Enter value to insert: ";
                cin >> data;
                insertAtPosition(head, position, data);
                break;

            case 5:
                printList(head);
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
                cout << "Please, enter a choice between 1–6 (*-*)\n";
        }

    } while (choice != 6);

    return 0;
}
