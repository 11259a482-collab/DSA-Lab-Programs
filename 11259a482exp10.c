Experiment 10 :-
Aim:-To write a C program to implement a Circular Queue using a Linked List and perform operations like Enqueue, Dequeue and Display.
Algorithm
1. Start.
2. Create a node with data and next fields.
3. Initialize front = NULL and rear = NULL.
4. Enqueue:
   - Create a new node and read data.
   - If the queue is empty, set front = rear = newnode.
   - Otherwise, insert the node at the rear.
   - Set rear->next = front.
5. Dequeue:
   - If the queue is empty, display Queue Underflow.
   - If only one node exists, set front = rear = NULL.
   - Otherwise, move front to the next node and update rear->next = front.
6. Display: Traverse from front until front is reached again.
7. Repeat the operations until Exit.
8. Stop.
C Program:
#include <stdio.h>
#include <stdlib.h>
struct Node {
 int data;
 struct Node *next;
};
struct Node *front = NULL, *rear = NULL;
void enqueue(int value) {
 struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
 newNode->data = value;
 if (front == NULL) {
 front = rear = newNode;
 newNode->next = front;
 } else {
 rear->next = newNode;
 rear = newNode;
 rear->next = front;
 }
 printf("%d enqueued.\n", value);
}
void dequeue() {
 if (front == NULL) {
 printf("Queue underflow\n");
 return;
 }
 if (front == rear) {
 printf("%d dequeued.\n", front->data);
 free(front);
 front = rear = NULL;
return;
 }
 struct Node *temp = front;
 front = front->next;
 rear->next = front;
 printf("%d dequeued.\n", temp->data);
 free(temp);
}
void display() {
 if (front == NULL) {
 printf("Queue is empty.\n");
 return;
 }
 struct Node *temp = front;
 printf("Queue elements: ");
 do {
 printf("%d ", temp->data);
 temp = temp->next;
 } while (temp != front);
 printf("\n");
}
int main() {
 int choice, value;
 do {
 printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter value: ");
 scanf("%d", &value);
enqueue(value);
 break;
 case 2:
 dequeue();
 break;
 case 3:
 display();
 break;
 case 4:
 printf("Exiting...\n");
 break;
 default:
 printf("Invalid choice.\n");
 }
 } while (choice != 4);
 return 0;
}
