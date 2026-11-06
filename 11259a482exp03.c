Experiment 3 – Stack Using Array
Program 1: PUSH, POP and DISPLAY Operations
Aim: To write and execute a C program to implement a stack using an array and perform the operations PUSH, POP and DISPLAY.

Algorithm:
1. Start.
2. Declare an array stack[MAX] and set top = -1.
3. Display the menu:
   - Push
   - Pop
   - Display
   - Exit
4. For Push:
   - Check if top == MAX-1.
   - If yes, display Stack Overflow.
   - Otherwise, increment top and insert the element.
5. For Pop:
   - Check if top == -1.
   - If yes, display Stack Underflow.
   - Otherwise, display and remove stack[top], then decrement top.
6. For Display:
   - If top == -1, display Stack is Empty.
   - Otherwise, display elements from top to 0.
7. Repeat steps 3–6 until the user selects Exit.
8. Stop.
Program:

#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int value) {
    if(top == MAX-1)
        printf("Stack Overflow\n");
    else {
        stack[++top] = value;
        printf("Element inserted\n");
    }
}

void pop() {
    if(top == -1)
        printf("Stack Underflow\n");
    else
        printf("Deleted element: %d\n", stack[top--]);
}

void display() {
    int i;

    if(top == -1)
        printf("Stack is Empty\n");
    else {
        for(i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    int ch, x;

    do {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                push(x);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exit\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while(ch != 4);

    return 0;
}
