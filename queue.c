#include <stdio.h>
#define N 3

void enqueue(int x, int* front, int* rear, int queue[]) {
    if (*rear == N - 1) {
        printf("Queue is full\n");
    } else if (*front == -1 && *rear == -1) {
        *front = 0;
        *rear = 0;
        queue[*rear] = x;
    } else {
        (*rear)++;
        queue[*rear] = x;
    }
}

void dequeue(int* front, int* rear, int queue[]) {
    if (*front == -1 && *rear == -1) {
        printf("Queue is empty\n");
    } else {
        int val = queue[*front];
        printf("Dequeued: %d\n", val);
        if (*front == *rear) { // Queue has only one element
            *front = -1;
            *rear = -1;
        } else {
            (*front)++;
        }
    }
}

void display(int* front, int* rear, int queue[]) {
    if (*front == -1 && *rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = *front; i <= *rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int queue[N];
    int front = -1;
    int rear = -1;

    while (1) {
        printf("ENTER 1 TO INSERT AN ELEMENT\n");
        printf("ENTER 2 TO DELETE AN ELEMENT\n");
        printf("ENTER 3 TO DISPLAY THE QUEUE\n");
        printf("ENTER 4 TO EXIT\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            int x;
            printf("Enter value to insert: ");
            scanf("%d", &x);
            enqueue(x, &front, &rear, queue);
        } else if (choice == 2) {
            dequeue(&front, &rear, queue);
        } else if (choice == 3) {
            display(&front, &rear, queue);
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid output\n");
        }
    }

    return 0;
}
