#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert elements at end
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

// Function to print linked list
void printList(Node* head) {
    cout << "\nLinked List: ";
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

// Function to sort the linked list
// order = 1 for ascending, 2 for descending
void sortLinkedList(Node* head, int order) {
    if (head == nullptr || head->next == nullptr)
        return;

    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if ((order == 1 && ptr1->data > ptr1->next->data) || 
                (order == 2 && ptr1->data < ptr1->next->data)) {
                swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    Node* head = nullptr;
    int choice, value, order;

    cout << "=== Linked List Sorting Program ===\n";

    do {
        cout << "\n1. Insert Element\n";
        cout << "2. Display List\n";
        cout << "3. Sort List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtEnd(head, value);
                break;

            case 2:
                printList(head);
                break;

            case 3:
                cout << "Choose sort order:\n1. Ascending\n2. Descending\nEnter choice: ";
                cin >> order;
                if (order != 1 && order != 2) {
                    cout << "Invalid choice!\n";
                    break;
                }
                sortLinkedList(head, order);
                cout << "List sorted successfully.\n";
                printList(head);
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
