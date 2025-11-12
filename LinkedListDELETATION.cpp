#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }            
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(Node* node) {
    while (node) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("null\n");
}

// Function to delete a node by value
Node* deleteNode(Node* head, int value) {
    Node* temp = head;
    Node* prev = NULL;

    // Case 1: List is empty
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    // Case 2: Node to delete is the head
    if (temp != NULL && temp->data == value) {
        head = temp->next;  // move head
        free(temp);
        printf("Deleted %d from the list.\n", value);
        return head;
    }

    // Case 3: Search for the node to delete
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If not found
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return head;
    }

    // Unlink the node
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", value);
    return head;
}

int main() {
    // Create nodes
    Node* node1 = createNode(3);
    Node* node2 = createNode(5);
    Node* node3 = createNode(13);
    Node* node4 = createNode(2);

    // Link nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    Node* head = node1;

    printf("Original Linked List: ");
    printList(head);

    // Ask user which value to delete
    int delValue;
    printf("Enter the value to delete: ");
    scanf("%d", &delValue);

    // Delete the node
    head = deleteNode(head, delValue);

    // Print the updated list
    printf("Updated Linked List: ");
    printList(head);

    // Free remaining nodes
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
