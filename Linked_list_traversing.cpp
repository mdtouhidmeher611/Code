#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert elements at the end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
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

// Function to display the list
void displayList(Node* head) {
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

// Function to find the sum of all elements
int findSum(Node* head) {
    int sum = 0;
    Node* temp = head;
    while (temp != nullptr) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

// Function to find the product of all elements
int findProduct(Node* head) {
    if (head == nullptr) return 0;
    int product = 1;
    Node* temp = head;
    while (temp != nullptr) {
        product *= temp->data;
        temp = temp->next;
    }
    return product;
}

// Function to find maximum element
int findMax(Node* head) {
    if (head == nullptr) return 0;
    int maxVal = head->data;
    Node* temp = head->next;
    while (temp != nullptr) {
        if (temp->data > maxVal)
            maxVal = temp->data;
        temp = temp->next;
    }
    return maxVal;
}

// Function to find minimum element
int findMin(Node* head) {
    if (head == nullptr) return 0;
    int minVal = head->data;
    Node* temp = head->next;
    while (temp != nullptr) {
        if (temp->data < minVal)
            minVal = temp->data;
        temp = temp->next;
    }
    return minVal;
}

// Function to find average
double findAverage(Node* head) {
    if (head == nullptr) return 0;
    int sum = 0, count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        sum += temp->data;
        count++;
        temp = temp->next;
    }
    return (double)sum / count;
}

int main() {
    Node* head = nullptr;
    int choice, value;

    cout << "=== Linked List Mathematical Operations ===\n";

    do {
        cout << "\n1. Insert Element\n";
        cout << "2. Display List\n";
        cout << "3. Sum of Elements\n";
        cout << "4. Product of Elements\n";
        cout << "5. Maximum Element\n";
        cout << "6. Minimum Element\n";
        cout << "7. Average\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtEnd(head, value);
                break;

            case 2:
                displayList(head);
                break;

            case 3:
                cout << "Sum of elements = " << findSum(head) << endl;
                break;

            case 4:
                cout << "Product of elements = " << findProduct(head) << endl;
                break;

            case 5:
                cout << "Maximum element = " << findMax(head) << endl;
                break;

            case 6:
                cout << "Minimum element = " << findMin(head) << endl;
                break;

            case 7:
                cout << "Average = " << findAverage(head) << endl;
                break;

            case 8:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 8);

    return 0;
}
