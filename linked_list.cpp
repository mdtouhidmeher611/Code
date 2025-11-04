#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    // Create 3 nodes
    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;

    // Allocate memory dynamically
    head = new Node();
    second = new Node();
    third = new Node();

    // Assign data and link nodes
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = nullptr;

    // Print the linked list
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    // Free memory
    delete head;
    delete second;
    delete third;

    return 0;
}
