Experiment 6 – Simple Queue Using Array
Aim
To write a C program to implement a simple queue using an array and perform insertion, deletion and display operations.
  
Algorithm
1. Start.
2. Declare an array queue[MAX] and initialize front = -1 and rear = -1.
3. Display the menu:
   - Insertion
   - Deletion
   - Display
   - Exit
4. For Insertion:
- Check if rear == MAX-1.
- If yes, display Queue Overflow.
- Otherwise, insert the element at the rear position.
- If front == -1, set front = 0.
5. For Deletion:
- Check if front == -1 or front > rear.
- If yes, display Queue Underflow.
- Otherwise, delete the element at the front position.
- Increment front.
6. For Display:
- If the queue is empty, display Queue is Empty.
- Otherwise, display elements from front to rear.
7. Repeat until Exit is selected.
8. Stop.
  
C Program Simple Queue program using C:-
#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue()
{
 int value;
 if (rear == MAX - 1)
 {
 printf("Queue Overflow\n");
 }
 else
 {
 printf("Enter the element: ");
 scanf("%d", &value);
 if (front == -1)
 front = 0;
 rear++;
 queue[rear] = value;
 printf("%d inserted into the queue\n", value);
 }
}
void dequeue()
{
 if (front == -1 || front > rear)
 {
 printf("Queue Underflow\n");
 }
 else
 {
 printf("%d deleted from the queue\n", queue[front]);
 front++;
 if (front > rear)
 {
 front = -1;
 rear = -1;
 }
 }
}
void display()
{
 int i;
 if (front == -1)
 {
 printf("Queue is empty\n");
 }
 else
 {
 printf("Queue elements are: ");
 for (i = front; i <= rear; i++)
 {
 printf("%d ", queue[i]);
 }
 printf("\n");
 }
}
int main()
{
 int choice;
 while (1)
 {
 printf("\n--- QUEUE OPERATIONS ---\n");
 printf("1. Enqueue\n");
 printf("2. Dequeue\n");
 printf("3. Display\n");
 printf("4. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice)
 {
 case 1:
 enqueue();
 break;
 case 2:
 dequeue();
 break;
 case 3:
 display();
 break;
 case 4:
 return 0;
 default:
 printf("Invalid choice\n");
 }
 }
 return 0;
