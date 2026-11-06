Experiment 1:- Araay Operations
Program 1.1: Creating an array and storing elements entered by the user

Aim: To write a C program to create an array and store elements entered by the user.

Algorithm:
1. Start.
2. Declare an array and variables.
3. Read the number of elements.
4. Read array elements using a loop.
5. Display the array elements.
6. Stop.
  
C Program:
#include <stdio.h>
  int main() {
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Array elements are: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

Program 1.2: Traverse and display all the elements of an array
Aim: To write a C program to traverse and display all the elements of an array.

Algorithm:
1. Start.
2. Declare an array and variables.
3. Read the number of elements.
4. Read array elements.
5. Traverse the array using a loop.
6. Display all elements.
7. Stop.

C Program:  
#include <stdio.h>

int main() {
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Array elements are: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}


Program 1.3 – Insertion in an Array.
Aim
To write a C program to insert an element at a specific position in an array.
Algorithm
1. Start.
2. Read the number of elements and array elements.
3. Read the element and position to insert.
4. Shift elements one position to the right.
5. Insert the element at the given position.
6. Display the updated array.
7. Stop.

C Program: 
#include <stdio.h>

int main() {
    int a[100], n, i, pos, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element and position: ");
    scanf("%d%d", &x, &pos);

    for(i = n; i >= pos; i--)
        a[i] = a[i-1];

    a[pos-1] = x;
    n++;

    printf("Array after insertion: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}


Program 1.4: Deletion of an Element from a Specified Position in an Array
Aim: To write a C program to delete an element from a specified position in an array.

Algorithm:
1. Start.
2. Read the number of elements and array elements.
3. Read the position to delete.
4. Shift the elements one position to the left.
5. Decrease the array size by one.
6. Display the updated array.
7. Stop.
C Program:

#include <stdio.h>

int main() {
    int a[100], n, i, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    for(i = pos-1; i < n-1; i++)
        a[i] = a[i+1];

    n--;

    printf("Array after deletion: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}


Program 1.5: Linear Search in an Array
Aim: To write a C program to search for an element in an array using the Linear Search technique.

Algorithm:
1. Start.
2. Read the number of elements and array elements.
3. Read the element to be searched.
4. Compare the search element with each array element.
5. If found, display its position.
6. Otherwise, display "Element not found".
7. Stop.
C Program:

#include <stdio.h>

int main() {
    int a[100], n, i, key, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        if(a[i] == key) {
            printf("Element found at position %d", i+1);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Element not found");

    return 0;
}
