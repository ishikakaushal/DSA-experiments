#include <stdio.h>
#define MAX 5
char queue[MAX];
int front = -1, rear = -1;
int isFull() {
  return (front == (rear + 1) % MAX);
}
int isEmpty() {
    return (front == -1);
}
void insert(char element) {
    if (isFull()) {
        printf("\nQueue Overflow! Cannot insert '%c'.", element);
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = element;
    printf("\nInserted: %c", element);
}
void deleteElement() {
    if (isEmpty()) {
        printf("\nQueue Underflow! Nothing to delete.");
        return;
    }
    printf("\nDeleted: %c", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}
void display() {
    if (isEmpty()) {
        printf("\nQueue is Empty!");
        return;
    }
    printf("\nCircular Queue: ");
    int i = front;
    while (1) {
        printf("%c ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}
int main() {
    int choice;
    char element;
    printf("===== CIRCULAR QUEUE IMPLEMENTATION =====\n");
    do {
        printf("\n\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &element);
                insert(element);
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting Program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.");
        }
    } while (choice != 4);
    return 0;
}
