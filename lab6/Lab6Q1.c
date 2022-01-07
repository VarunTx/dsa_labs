//LAB 6 Q1
//NAME: VARUN TALARI
//ROLL NO: EC20B1041
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
} *head;

void firstToLast(struct node **);
void swapListData(struct node **, int);
void swap(int *, int *);
struct node *display(struct node *);

int main()
{
    int data1 = 0;
    struct node *ptr;
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    if (node1 == NULL)
    {
        printf("\nERROR: Memory cannot be allocated\n");
        return -1;
    }
    printf("\n\nEnter the value of First node: ");
    scanf("%d", &data1);

    // Creates First node

    node1->val = data1;
    node1->next = NULL;
    head = node1;
    ptr = head;
    int n, DATA;
    printf("\nEnter the number of Nodes to be in Linked List: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("\nERROR: Input should be Positive integers greater than Zero");
        return -1;
    }
    struct node *new_node;

    // Creates rest of Nodes acc to User

    for (int i = 2; i <= n; i++)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        if (new_node == NULL)
        {
            printf("\nERROR: Memory cannot be allocated\n");
            return -1;
        }
        printf("\n\nEnter the value of %d node: ", i);
        scanf("%d", &DATA);

        new_node->val = DATA;
        new_node->next = NULL;

        ptr->next = new_node;
        ptr = ptr->next;
    }
    int choice = 0;

    // Taking User's choice

    while (1)
    {
        printf("\n\n1. Move First node to Last ");
        printf("\n2. Swap values at indices (1,2), (3,4) and so on ");
        printf("\n3. Exit\n\n");
        printf("\nEnter your choice:  ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            firstToLast(&head);
            display(head);
            break;
        case 2:
            swapListData(&head, n);
            display(head);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\nERROR: ONLY CHOOSE THE OPTIONS LISTED BELOW ");
            break;
        }
    }
}


// Move the First node to the End of List

void firstToLast(struct node **head)
{
    if (*head == NULL)
    {
        printf("\nERROR: List is empty\n");
        return;
    }

    struct node *ptr = *head;
    struct node *temp = *head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    // Makes the last node point to First and Updates the new *Head
    ptr->next = temp;
    *head = temp->next;
    temp->next = NULL;
}


// Swaps the values of LL at indices (1,2) (3,4) and so on

void swapListData(struct node **head, int n)
{
    if (*head == NULL)
    {
        printf("\nERROR: List is empty\n");
        return;
    }

    struct node *ptr = *head;
    // Taking two unique nodes in each iteration and swapping their value
    while (ptr != NULL && ptr->next != NULL)
    {
        swap(&ptr->val, &ptr->next->val);
        ptr = ptr->next->next;
    }
}


// Interchanges the values of two variables

void swap(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}


// Displays the Linked List

struct node *display(struct node *head)
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("\nERROR: List is empty\n");
        return head;
    }
    printf("\n\nThe List: \n");
    //Pointing to next node and printing its value in each iteration
    while (ptr != NULL)
    {
        printf("%d \n", ptr->val);
        ptr = ptr->next;
    }
    return head;
}