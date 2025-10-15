#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else
        return stack[top--];
}

char peek() {
    return (top == -1) ? '\0' : stack[top];
}

// Function to define precedence of operators
int precedence(char c) {
    switch (c) {
        case '^': return 3;
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Function to check associativity of operators
int isRightAssociative(char op) {
    return (op == '^'); // ^ is right-associative
}

// Function to convert Infix to Postfix
void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int i = 0, k = 0;
    char ch;

    printf("\nInfix Expression: %s\n", infix);
    printf("Postfix Conversion Steps:\n");

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            // Operand directly goes to output
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && peek() != '(')
                postfix[k++] = pop();
            if (top != -1 && peek() == '(')
                pop(); // remove '('
        }
        else { // Operator
            while (top != -1 && 
                  (precedence(peek()) > precedence(ch) ||
                  (precedence(peek()) == precedence(ch) && !isRightAssociative(ch)))
                  && peek() != '(') {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);

    // Remove trailing newline from fgets
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix);   
    return 0;
}

