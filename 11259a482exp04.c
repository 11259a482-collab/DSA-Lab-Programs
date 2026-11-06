Experiment 4 – Conversion of Infix to Postfix Expression
Aim
To write a C program to convert an infix expression into a postfix expression using a stack.
Algorithm
1. Start.
2. Read the infix expression.
3. Initialize an empty stack.
4. Scan the expression from left to right.
5. If the character is an operand, add it to the postfix expression.
6. If the character is (, push it onto the stack.
7. If the character is ), pop operators until ( is found.
8. If the character is an operator, pop operators with higher or equal precedence and then push the current operator.
9. Pop all remaining operators from the stack.
10. Display the postfix expression.
11. Stop.
C Program:-
  
#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int priority(char x) {
    if(x == '^')
        return 3;
    if(x == '*' || x == '/')
        return 2;
    if(x == '+' || x == '-')
        return 1;
    return 0;
}

int main() {
    char infix[100], postfix[100];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    for(i = 0; infix[i] != '\0'; i++) {
        char x = infix[i];

        if(isalnum(x))
            postfix[j++] = x;

        else if(x == '(')
            push(x);

        else if(x == ')') {
            while(top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            if(top != -1)
                pop();
        }

        else {
            while(top != -1 && stack[top] != '(' &&
                  priority(stack[top]) >= priority(x))
                postfix[j++] = pop();

            push(x);
        }
    }

    while(top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix expression: %s", postfix);

    return 0;
}
