#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to print the linked list
void printList(Node* head) {
    cout << "\nCurrent Linked List: ";
    if (head == nullptr) {
        cout << "Empty\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Insert at end (for building list easily)
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is already empty!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted: " << temp->data << endl;
    delete temp;
}

// Delete from end
void deleteFromEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is already empty!\n";
        return;
    }

    if (head->next == nullptr) {
        cout << "Deleted: " << head->data << endl;
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;

    cout << "Deleted: " << temp->next->data << endl;
    delete temp->next;
    temp->next = nullptr;
}

// Delete a specific value
void deleteValue(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        cout << "Deleted: " << value << endl;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value)
        temp = temp->next;

    if (temp->next == nullptr) {
        cout << "Value " << value << " not found in the list.\n";
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    cout << "Deleted: " << value << endl;
    delete toDelete;
}

int main() {
    Node* head = nullptr;
    int choice, value;

    cout << "=== Linked List Deletion Menu ===\n";

    do {
        cout << "\n1. Insert Value\n";
        cout << "2. Delete from Beginning\n";
        cout << "3. Delete from End\n";
        cout << "4. Delete a Specific Value\n";
        cout << "5. Display List\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtEnd(head, value);
                break;

            case 2:
                deleteFromBeginning(head);
                break;

            case 3:
                deleteFromEnd(head);
                break;

            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteValue(head, value);
                break;

            case 5:
                printList(head);
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
