//LAB 9 Q3 (Circular Queue using array)
//NAME: VARUN TALARI
//ROLL NO: EC20B1041
#include <stdio.h>
#include <stdlib.h>

void count(int queue[], int size);
void insert(int queue[], int size, int num);
void delete (int queue[], int size);
void peek(int queue[]);
void display(int queue[], int size);
void largest(int queue[], int size);

void topnbot(int queue[]);

int front = -1;
int rear = -1;

void main()
{
    int size = 0;
    printf("\nEnter Array size to implement Circular Queue: ");
    scanf("%d", &size);
    int queue[size];
    int data = 0, choice = 0;

    // Taking User's choice

    while (1)
    {
        printf("\n\n1. Insert ");
        printf("\n2. Delete ");
        printf("\n3. Peek ");
        printf("\n4. Display Queue");
        printf("\n5. To Count items ");
        printf("\n6. Find Largest element ");
        printf("\n7. Exit ");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter number to be inserted: ");
            scanf("%d", &data);
            insert(queue, size, data);
            display(queue, size);
            topnbot(queue);
            break;
        case 2:
            delete (queue, size);
            display(queue, size);
            topnbot(queue);
            break;
        case 3:
            peek(queue);
            break;
        case 4:
            display(queue, size);
            break;
        case 5:
            count(queue, size);
            break;
        case 6:
            largest(queue, size);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("\n\nERROR: ONLY CHOOSE THE OPTIONS LISTED BELOW ");
            break;
        }
    }
}

// Displays the Front and Rear indices
void topnbot(int queue[])
{
    printf("\nFront: %d", front);
    printf(" Rear: %d", rear);
}

// Counts the number of elements present in the Cir.Queue
void count(int queue[], int size)
{
    int counter = 0;
    if (front == -1 && rear == -1)
    {
        printf("\n\nERROR: Queue is empty");
        return;
    }

    if (front <= rear)
    {
        counter = rear - front + 1;
    }
    else
    {
        int i = 0;

        i = front;
        while (i < size)
        {
            i++;
            counter++;
        }
        i = 0;
        while (i <= rear)
        {
            i++;
            counter++;
        }
    }
    printf("\n\nNumber of items present in Queue: %d", counter);
}

// Inserts an element at the Rear of the Cir.Queue
void insert(int queue[], int size, int num)
{
    if ((rear + 1) % size == front)
    {
        printf("\n\nERROR: Overflow, queue is full");
        return;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
            rear = (rear + 1) % size;
            queue[rear] = num;
        }
        else
        {
            rear = (rear + 1) % size;
            queue[rear] = num;
        }
    }
}

// Deletes an element from the Front of the Cir.Queue
void delete (int queue[], int size)
{
    if (front == -1 && rear == -1)
    {
        printf("\n\nERROR: Underflow, queue is empty");
        return;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
}

// Displays the front element of Cir.Queue 
void peek(int queue[])
{
    printf("\n\nElement at Front end of Queue is: %d", queue[front]);
}

// Displays the elements of the Cir.Queue
void display(int queue[], int size)
{
    if (front == -1 && rear == -1)
    {
        printf("\n\nERROR: Queue is empty");
        return;
    }
    printf("\n\nElements of the Queue: \n");
    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    else
    {
        int i = front;
        while (i < size)
        {
            printf("%d ", queue[i]);
            i++;
        }
        i = 0;
        while (i <= rear)
        {
            printf("%d ", queue[i]);
            i++;
        }
    }
}

// Finds the largest element present in the Cir.Queue
void largest(int queue[], int size)
{
    if (front == -1 && rear == -1)
    {
        printf("\n\nERROR: Queue is empty");
        return;
    }
    int L = 0;
    L = queue[front];
    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
        {
            if (queue[i] > L)
            {
                L = queue[i];
            }
        }
    }
    else
    {
        int i = front;
        while (i < size)
        {
            if (queue[i] > L)
            {
                L = queue[i];
            }
            i++;
        }
        i = 0;
        while (i <= rear)
        {
            if (queue[i] > L)
            {
                L = queue[i];
            }
            i++;
        }
    }
    printf("\n\nLargest element in the Queue is: %d", L);
}
