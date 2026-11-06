Experiment 5:- Postfix Expression Evaluation Using Stack
Aim
To write a C program to evaluate a postfix expression using a stack.
Algorithm
1. Start.
2. Read the postfix expression.
3. Initialize an empty stack.
4. Scan the expression from left to right.
5. If the character is an operand, push it onto the stack.
6. If the character is an operator:
   - Pop two elements from the stack.
   - Perform the operation.
   - Push the result onto the stack.
7. Repeat until the expression ends.
8. Pop and display the final result.
9. Stop.
C Program:

#include <stdio.h>
#include <ctype.h>

int stack[100], top = -1;

int main() {
    char exp[100], ch;
    int i, a, b;

    printf("Enter postfix expression: ");
    scanf("%99s", exp);

    for(i = 0; exp[i] != '\0'; i++) {
        ch = exp[i];

        if(isdigit(ch))
            stack[++top] = ch - '0';

        else {
            b = stack[top--];
            a = stack[top--];

            switch(ch) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
            }
        }
    }

    printf("Result: %d", stack[top]);

    return 0;
}
