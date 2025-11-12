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

// Function to search for a value in the list
Node* searchNode(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current;  // Found
        }
        current = current->next;
    }
    return NULL;  // Not found
}

int main() {
    // Create nodes
    Node* node1 = createNode(3);
    Node* node2 = createNode(5);
    Node* node3 = createNode(13);
    Node* node4 = createNode(2);

    // Link the nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Print the linked list
    printf("Linked List: ");
    printList(node1);

    // Get user input
    int searchValue;
    printf("Enter a number to search for: ");
    scanf("%d", &searchValue);

    // Search the list
    Node* result = searchNode(node1, searchValue);

    if (result != NULL) {
        printf(" Value %d found in the list!\n", searchValue);
    } else {
        printf(" Value %d not found in the list.\n", searchValue);
    }

    // Free memory
    free(node1);
    free(node2);
    free(node3);
    free(node4);

    return 0;
}
