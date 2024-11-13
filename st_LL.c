#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;  // Initialize the stack

// Push function to add an element to the stack
void push(int val) {
    // Create a new node
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {  // Check if memory allocation succeeded
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = val;
    // Make the new node point to the current head
    newNode->next = head;
    // Make the new node the head of the stack
    head = newNode;
}

// Pop function to remove an element from the stack
void pop() {
    struct node *temp;
    if (head == NULL) {
        printf("Stack is Empty\n");
    } else {
        printf("Popped element = %d\n", head->data);
        // Backup the head node
        temp = head;
        // Move the head to the next node
        head = head->next;
        // Free the memory of the popped node
        free(temp);
    }
}

// Print the stack (linked list)
void printList() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    // Iterate through the linked list and print each node's data
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Pushing elements onto the stack
    push(10);
    push(20);
    push(30);

    // Printing the current stack
    printf("Linked List (Stack):\n");
    printList();

    // Performing pop operation
    pop();
    printf("After pop, the new linked list (stack):\n");
    printList();

    pop();
    printf("After pop, the new linked list (stack):\n");
    printList();

    // Popping the last element
    pop();
    printf("After pop, the new linked list (stack):\n");
    printList();

    return 0;
}
