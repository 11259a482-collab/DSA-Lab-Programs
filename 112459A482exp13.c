 Experiment 13:-Implementation of Hashing with Collision Resolution 
using Linear Probing
Aim:-
To write a C program to implement a hash table using the division hash function 
h(key) = key % TABLE_SIZE, and resolve collisions using linear probing.
Algorithm:-
1. Create a hash table of fixed size TABLE_SIZE and initialize all slots to 
EMPTY.
2. To insert a key: compute its home index using the hash function h(key) = 
key % TABLE_SIZE.
3. If the slot at the home index is occupied (collision), probe linearly (index 
= (index + 1) % TABLE_SIZE) until an empty slot is found, then insert the 
key there; if the table becomes full before an empty slot is found, report 
overflow.
4. To search for a key: compute its home index, then probe linearly from that 
index, comparing each occupied slot's value to the key, until the key is found 
or an empty slot / the starting index is reached again.
5. Display the contents of the hash table, showing the index and the value (or 
EMPTY) stored at each slot.
 C Program:-
#include <stdio.h>
#define TABLE_SIZE 10
#define EMPTY -1
int hashTable[TABLE_SIZE];
void initTable() {
 for (int i = 0; i < TABLE_SIZE; i++)
 hashTable[i] = EMPTY;
}
int hashFunction(int key) {
 return key % TABLE_SIZE;
} void insert(int key) {
 int index = hashFunction(key);
 int startIndex = index;
 int probes = 0;
 while (hashTable[index] != EMPTY) {
 index = (index + 1) % TABLE_SIZE;
 probes++;
 if (index == startIndex) {
 printf("Hash table is full. Cannot insert %d.\n", key);
 return;
 }
 }
 hashTable[index] = key;
 printf("Key %d inserted at index %d (probes: %d).\n", key, index, probes);
}
int search(int key) {
 int index = hashFunction(key);
 int startIndex = index;
 while (hashTable[index] != EMPTY) {
 if (hashTable[index] == key)
 return index;
 index = (index + 1) % TABLE_SIZE;
 if (index == startIndex)
 break;
 }
 return -1;
}
void display() {
 printf("\nIndex\tValue\n");
 for (int i = 0; i < TABLE_SIZE; i++) {
 if (hashTable[i] == EMPTY)
 printf("%d\tEMPTY\n", i);
 else
 printf("%d\t%d\n", i, hashTable[i]);
 }
}
int main() { int n, key, choice, result;
 initTable();
 printf("Enter number of keys to insert: ");
 scanf("%d", &n);
 printf("Enter %d keys: ", n);
 for (int i = 0; i < n; i++) {
 scanf("%d", &key);
 insert(key);
 }
 display();
 do {
 printf("\n1. Search\n2. Insert\n3. Display\n4. Exit\nEnter choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter key to search: ");
 scanf("%d", &key);
 result = search(key);
 if (result != -1)
 printf("Key %d found at index %d.\n", key, result);
 else
 printf("Key %d not found.\n", key);
 break;
 case 2:
 printf("Enter key to insert: ");
 scanf("%d", &key);
 insert(key);
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
 } while (choice != 4); return 0;
}
