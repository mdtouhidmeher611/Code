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

// Function to sort the linked list (ascending order)
void sortList(Node* head) {
    Node* current = head;
    Node* index = NULL;
    int temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->data > index->data) {
                // swap data
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }

    printf("Linked list sorted successfully!\n");
}

int main() {
    Node* node1 = createNode(3);
    Node* node2 = createNode(5);
    Node* node3 = createNode(13);
    Node* node4 = createNode(2);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    Node* head = node1;

    printf("Original Linked List: ");
    printList(head);

    // Sort the linked list
    sortList(head);

    printf("Sorted Linked List: ");
    printList(head);

    // Free memory
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
Sorting