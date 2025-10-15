#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
int stack[MAX];
int top = -1;
// Function Prototypes
void push(int);
int pop();
void checkPalindrome();
void display();
void stackStatus();
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", val);
    } else {
        stack[++top] = val;
        printf("%d pushed to stack.\n", val);
    }
}
int pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    } else {
        int popped = stack[top--];
        printf("%d popped from stack.\n", popped);
        return popped;
    }
}
void checkPalindrome() {
    char str[100], temp[100];
    int i, len;
    printf("Enter a string to check palindrome: ");
    scanf("%s", str);
    len = strlen(str);
    top = -1; // Reset stack for new use
    for (i = 0; i < len; i++) {
        push(str[i]);
    }
    for (i = 0; i < len; i++) {
        temp[i] = pop();
    }
    temp[i] = '\0';
    if (strcmp(str, temp) == 0) {
        printf("The string '%s' is a Palindrome.\n", str);
    } else {
        printf("The string '%s' is NOT a Palindrome.\n", str);
    }
}
void stackStatus() {
    if (top == -1)
        printf("Stack is EMPTY.\n");
    else if (top == MAX - 1)
        printf("Stack is FULL.\n");
    else
        printf("Stack has %d elements.\n", top + 1);
}
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (Top to Bottom):\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}
int main() {
    int choice, value;
    do {
        printf("\n=== STACK MENU ===\n");
        printf("1. Push an Element\n");
        printf("2. Pop an Element\n");
        printf("3. Check Palindrome (Using Stack)\n");
        printf("4. Demonstrate Overflow/Underflow\n");
        printf("5. Display Stack Status\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                printf("Demonstrating Stack Overflow:\n");
                top = MAX - 2;
                push(10);
                push(20); // should show overflow
                printf("Demonstrating Stack Underflow:\n");
                top = -1;
                pop(); // should show underflow
                break;
            case 5:
                stackStatus();
                display();
                break;
            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}
