Experiment 9:-
Aim:-To write a C program to implement a Doubly Linked List and perform operations like Enqueue, Dequeue and Display.
Algorithm
1. Start.
2. Create a doubly linked list with prev and next pointers.
3. Initialize front = NULL and rear = NULL.
4. Enqueue: Create a new node and insert it at the rear end.
5. Update the prev and next pointers.
6. Dequeue: Delete the node from the front end.
7. Update the front pointer.
8. Display: Traverse from front to rear and print all elements.
9. Repeat the operations until Exit.
10. Stop.
C Program:
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue() {
    struct node *newnode;
    newnode = malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    newnode->prev = rear;

    if (rear == NULL)
        front = rear = newnode;
    else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() {
    struct node *temp;

    if (front == NULL) {
        printf("Queue is empty");
        return;
    }

    temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;
    else
        front->prev = NULL;

    free(temp);
    printf("Deleted");
}

void display() {
    struct node *temp = front;

    if (front == NULL) {
        printf("Queue is empty");
        return;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int ch;

    do {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
        }
    } while (ch != 4);

    return 0;
}
