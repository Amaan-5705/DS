#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int val) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    // If it is the first node
    if (front == NULL && rear == NULL) {
        // Make both front and rear point to the new node
        front = rear = newNode;
    } else {
        // Add newNode in rear->next
        rear->next = newNode;
        // Make the new node as the rear node
        rear = newNode;
    }
}

void dequeue() {
    // Used to free the first node after dequeue
    struct node *temp;

    if (front == NULL) {
        printf("Queue is Empty. Unable to perform dequeue\n");
    } else {
        // Take backup
        temp = front;
        // Make the front node point to the next node (logically removing the front element)
        front = front->next;

        // If front becomes NULL, set rear to NULL as well
        if (front == NULL) {
            rear = NULL;
        }

        // Free the first node
        free(temp);
    }
}

void printList() {
    struct node *temp = front;

    if (temp == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Queue: ");
    printList();

    dequeue();
    printf("After dequeue, the new Queue: ");
    printList();

    dequeue();
    printf("After dequeue, the new Queue: ");
    printList();

    return 0;
}
