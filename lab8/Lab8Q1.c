//LAB 8 Q1 (TWO STACKS IN A ARRAY)
//NAME: VARUN TALARI
//ROLL NO: EC20B1041
#include <stdio.h>
#include <stdlib.h>

void push1(int *, int, int, int *, int *);
void push2(int *, int, int, int *, int *);
void pop1(int *, int, int *);
void pop2(int *, int, int *);
void peek1(int *, int, int *);
void peek2(int *, int, int *);
void display1(int *, int, int *);
void display2(int *, int, int *);

int main()
{
    int MAX = 0;
    printf("\nEnter Array size to implement Stack: ");
    scanf("%d", &MAX);
    int top1 = -1;
    int top2 = MAX;
    int arr[MAX];

    int data = 0, choice = 0;

    // Taking User's choice

    while (1)
    {
        printf("\n\n1. Push in Stack 1 ");
        printf("\n2. Pop in Stack 1 ");
        printf("\n3. Peek in Stack 1 ");
        printf("\n4. Display Stack 1 ");
        printf("\n5. Push in Stack 2 ");
        printf("\n6. Pop in Stack 2 ");
        printf("\n7. Peek in Stack 2 ");
        printf("\n8. Display Stack 2 ");
        printf("\n9. Exit ");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter number to be pushed: ");
            scanf("%d", &data);
            push1(arr, MAX, data, &top1, &top2);
            display1(arr, MAX, &top1);
            break;
        case 2:
            pop1(arr, MAX, &top1);
            display1(arr, MAX, &top1);
            break;
        case 3:
            peek1(arr, MAX, &top1);
            break;
        case 4:
            display1(arr, MAX, &top1);
            break;
        case 5:
            printf("\nEnter number to be pushed: ");
            scanf("%d", &data);
            push2(arr, MAX, data, &top2, &top1);
            display2(arr, MAX, &top2);
            break;
        case 6:
            pop2(arr, MAX, &top2);
            display2(arr, MAX, &top2);
            break;
        case 7:
            peek2(arr, MAX, &top2);
            break;
        case 8:
            display2(arr, MAX, &top2);
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("\n\nERROR: ONLY CHOOSE THE OPTIONS LISTED BELOW ");
            break;
        }
    }
}

// Pushes/inserts an element to Stack 1

void push1(int *arr, int MAX, int data, int *top1, int *top2)
{
    if ((*top1) + 1 >= *top2 || (*top1) == MAX - 1)
    {
        printf("\n\nERROR: Overflow");
        return;
    }
    // Increasing the index of top element and assigning the data
    *top1 = *top1 + 1;
    *(arr + (*top1)) = data;
}

// Pushes/inserts an element to Stack 2

void push2(int *arr, int MAX, int data, int *top2, int *top1)
{
    if ((*top2) - 1 <= *top1 || (*top2) == -1)
    {
        printf("\n\nERROR: Overflow");
        return;
    }
    // Increasing the index of top element and assigning the data
    *top2 = *top2 - 1;
    *(arr + (*top2)) = data;
}

// Deletes top most element from Stack 1

void pop1(int *arr, int MAX, int *top1)
{
    if ((*top1) == -1)
    {
        printf("\n\nERROR: Underflow");
        return;
    }
    *top1 = *top1 - 1;
}

// Deletes top most element from Stack 2

void pop2(int *arr, int MAX, int *top2)
{
    if ((*top2) == MAX)
    {
        printf("\n\nERROR: Underflow");
        return;
    }
    *top2 = *top2 + 1;
}

// Displays top most element in Stack 1

void peek1(int *arr, int MAX, int *top1)
{
    if ((*top1) == -1)
    {
        printf("\n\nERROR: Stack 1 is empty");
        return;
    }
    printf("\nTop element in Stack 1 is: %d", (*(arr + *top1)));
}

// Displays top most element in Stack 2

void peek2(int *arr, int MAX, int *top2)
{
    if ((*top2) == MAX)
    {
        printf("\n\nERROR: Stack 2 is empty");
        return;
    }
    printf("\nTop element in Stack 2 is: %d", (*(arr + *top2)));
}

// Displays entire Stack 1

void display1(int *arr, int MAX, int *top1)
{
    if ((*top1) == -1)
    {
        printf("\n\nERROR: Stack 1 is empty\n\n");
        return;
    }
    // Pointing to next node and printing its value in each iteration
    printf("\nStack 1 is: \n");
    for (int i = *top1; i > -1; i--)
    {
        printf("%d \n", *(arr + i));
    }
}

// Displays entire Stack 2

void display2(int *arr, int MAX, int *top2)
{
    if ((*top2) == MAX)
    {
        printf("\n\nERROR: Stack 2 is empty\n\n");
        return;
    }
    // Pointing to next node and printing its value in each iteration
    printf("\nStack 2 is: \n");
    for (int i = *top2; i < MAX; i++)
    {
        printf("%d \n", *(arr + i));
    }
}
