//LAB 9 Q1 (Queue using two Stacks)
//NAME: VARUN TALARI
//ROLL NO: EC20B1041
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct queue
{
    struct node *s1;
    struct node *s2;
};

void enqueue(struct queue *q, int data);
void dequeue(struct queue *q);
void peek(struct queue *q);
void displayqueue(struct queue *q, struct node **top);

void push_stack(struct node **top, int data);
int pop_stack(struct node **top);
int peek_stack(struct node **top);

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->s1 = NULL;
    q->s2 = NULL;

    int data = 0, choice = 0;

    // Taking User's choice

    while (1)
    {
        printf("\n\n1. Insert (Enqueue) ");
        printf("\n2. Delete (Dequeue) ");
        printf("\n3. Peek queue ");
        printf("\n4. Display queue ");
        printf("\n5. Exit ");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter number to be inserted: ");
            scanf("%d", &data);
            enqueue(q, data);
            printf("Enqueued %d, now ", data);
            peek(q);
            break;
        case 2:
            dequeue(q);
            printf("\nNow ");
            peek(q);
            break;
        case 3:
            peek(q);
            break;
        case 4:
            displayqueue(q, &q->s2);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\n\nERROR: ONLY CHOOSE THE OPTIONS LISTED BELOW ");
            break;
        }
    }
    return 0;
}

// Enqueues/Inserts an element to the End of Queue
void enqueue(struct queue *q, int data)
{
    push_stack(&q->s1, data);
}

// Dequeues/Deletes an element from the Front of Queue
void dequeue(struct queue *q)
{
    int temp;
    if (q->s2 == NULL && q->s1 == NULL)
    {
        printf("\nERROR: Queue is empty");
        return;
    }
    else
    {
        peek(q);
        temp = pop_stack(&q->s2);
        printf(" has been dequeued", temp);
    }
}

// Finds the top/front element in the Queue
void peek(struct queue *q)
{
    int temp;
    if (q->s2 == NULL && q->s1 == NULL)
    {
        printf("\nERROR: Queue is empty");
        return;
    }
    else
    {
        if (q->s2 == NULL)
        {
            while (q->s1 != NULL)
            {
                temp = pop_stack(&q->s1);
                push_stack(&q->s2, temp);
            }
        }
        temp = peek_stack(&q->s2);
        printf("The top element in Queue: %d", temp);
    }
}

//Displays the elements of Queue
void displayqueue(struct queue *q, struct node **top)
{
    int temp;
    if (q->s1 == NULL && q->s2 == NULL)
    {
        printf("\n\nThe Queue is empty");
        return;
    }
    else
    {
        while (q->s1 != NULL)
        {
            temp = pop_stack(&q->s1);
            push_stack(&q->s2, temp);
        }
        struct node *ptr = *top;
        printf("The final Queue is: \n");
        while (ptr != NULL)
        {
            printf("%d ", ptr->val);
            ptr = ptr->next;
        }
    }
}

// Pushes an element to the top of desired Stack
void push_stack(struct node **top, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("\nERROR: Memory cannot be allocated\n");
        return;
    }
    newnode->val = data;
    if (*top == NULL)
    {
        newnode->next = NULL;
        *top = newnode;
    }
    else
    {
        newnode->next = *top;
        *top = newnode;
    }
}

// Pops the top element from desired Stack
int pop_stack(struct node **top)
{
    int temp;
    struct node *ptr = *top;
    *top = ptr->next;
    temp = ptr->val;
    ptr->next = NULL;
    free(ptr);
    return temp;
}

// Finds the top element of the desired Stack
int peek_stack(struct node **top)
{
    int temp;
    temp = (*top)->val;
    return temp;
}

