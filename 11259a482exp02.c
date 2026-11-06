Experiment 2:- Structure Operations

Program 2:1:- Student Details Using Structure
Aim: To write a C program to store and display student details using structure.
Algorithm:
1. Start.
2. Define a structure named Student.
3. Declare variables for roll number, name and marks.
4. Read student details.
5. Display the student details.
6. Stop.
C Program:

#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student s;

    printf("Enter roll number: ");
    scanf("%d", &s.roll);

    printf("Enter name: ");
    scanf("%s", s.name);

    printf("Enter marks: ");
    scanf("%f", &s.marks);

    printf("\nStudent Details\n");
    printf("Roll Number: %d\n", s.roll);
    printf("Name: %s\n", s.name);
    printf("Marks: %.2f\n", s.marks);

    return 0;
}

Program 2.2: Mobile Phone Details Using Structure
Aim: To write a C program to store and display mobile phone details using a structure.

Algorithm:
1. Start.
2. Define a structure named Mobile.
3. Declare variables for brand, model and price.
4. Read mobile phone details.
5. Display the details.
6. Stop.
C Program:

#include <stdio.h>

struct Mobile {
    char brand[30];
    char model[30];
    float price;
};

int main() {
    struct Mobile m;

    printf("Enter brand: ");
    scanf("%s", m.brand);

    printf("Enter model: ");
    scanf("%s", m.model);

    printf("Enter price: ");
    scanf("%f", &m.price);

    printf("\nMobile Details\n");
    printf("Brand: %s\n", m.brand);
    printf("Model: %s\n", m.model);
    printf("Price: %.2f\n", m.price);

    return 0;
}

Program 2.3: Product Details Using Structure Pointer
Aim: To write a C program to store and display product details using a structure pointer.

Algorithm:
1. Start.
2. Define a structure named Product.
3. Declare product variables and a structure pointer.
4. Read product details using the pointer.
5. Display product details using the pointer.
6. Stop.
C Program:

#include <stdio.h>

struct Product {
    int id;
    char name[30];
    float price;
};

int main() {
    struct Product p;
    struct Product *ptr = &p;

    printf("Enter product ID: ");
    scanf("%d", &ptr->id);

    printf("Enter product name: ");
    scanf("%s", ptr->name);

    printf("Enter price: ");
    scanf("%f", &ptr->price);

    printf("\nProduct Details\n");
    printf("ID: %d\n", ptr->id);
    printf("Name: %s\n", ptr->name);
    printf("Price: %.2f\n", ptr->price);

    return 0;
}


Program 2.4: Dynamic Employee Record System Using Structure Pointers
Aim: To write a C program to build a dynamic employee record system using structure pointers.
Algorithm:
1. Start.
2. Define an Employee structure with ID, name and salary.
3. Display the menu.
4. Add employee records dynamically.
5. Display all employee records.
6. Search an employee using ID.
7. Delete an employee using ID.
8. Repeat until Exit is selected.
9. Free allocated memory and stop.
C Program:

#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[30];
    float salary;
    struct Employee *next;
};

struct Employee *head = NULL;

void add() {
    struct Employee *e, *p;
    e = malloc(sizeof(struct Employee));

    if(e == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter ID, Name and Salary: ");
    scanf("%d %29s %f", &e->id, e->name, &e->salary);

    e->next = NULL;

    if(head == NULL)
        head = e;
    else {
        p = head;
        while(p->next != NULL)
            p = p->next;
        p->next = e;
    }
    printf("Employee added\n");
}

void display() {
    struct Employee *p = head;

    if(p == NULL) {
        printf("No records found\n");
        return;
    }

    while(p != NULL) {
        printf("\nID: %d Name: %s Salary: %.2f\n",
               p->id, p->name, p->salary);
        p = p->next;
    }
}

void search() {
    int id;
    struct Employee *p = head;

    printf("Enter ID to search: ");
    scanf("%d", &id);

    while(p != NULL) {
        if(p->id == id) {
            printf("Employee found: %s %.2f\n",
                   p->name, p->salary);
            return;
        }
        p = p->next;
    }
    printf("Employee not found\n");
}

void delete() {
    int id;
    struct Employee *p = head, *prev = NULL;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    while(p != NULL && p->id != id) {
        prev = p;
        p = p->next;
    }

    if(p == NULL) {
        printf("Employee not found\n");
        return;
    }

    if(prev == NULL)
        head = p->next;
    else
        prev->next = p->next;

    free(p);
    printf("Employee deleted\n");
}

int main() {
    int ch;

    do {
        printf("\n1.Add 2.Display 3.Search 4.Delete 5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: delete(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while(ch != 5);

    while(head != NULL) {
        struct Employee *p = head;
        head = head->next;
        free(p);
    }

    return 0;
}

