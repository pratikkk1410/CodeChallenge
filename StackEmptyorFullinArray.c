#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack is full. Cannot push.\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is empty. Cannot pop.\n");
    } else {
        int popped = stack[top];
        top--;
        printf("%d popped from stack\n", popped);
    }
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

int size() {
    return top + 1;
}

int main() {
    int command, value;

    while (1) {
        if (scanf("%d", &command) != 1) break;

        switch (command) {
            case 1: 
                if (scanf("%d", &value) != 1) break;
                push(value);
                break;

            case 2: 
                pop();
                break;

            case 3:
                if (isEmpty()) {
                    printf("The stack is empty.\n");
                } else {
                    printf("The stack is not empty. Current size: %d\n", size());
                }
                break;

            case 4: 
                if (isFull()) {
                    printf("The stack is full.\n");
                } else {
                    printf("The stack is not full. Remaining capacity: %d\n", MAX - size());
                }
                break;

            case 5: 
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}
