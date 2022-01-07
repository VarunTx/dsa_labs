//LAB 7 Q1 (DOUBLY LINKED LIST)
//NAME: VARUN TALARI
//ROLL NO: EC20B1041
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
    struct node *prev;
} *head = NULL, *lastptr = NULL;

void reverse_DLL(struct node **);
void smallestnode_DLL(struct node **);
void sum_DLL(struct node **);
void insertnode_DLL(struct node **, struct node **, int);
struct node *display_DLL(struct node *);

int main()
{
    int data = 0, choice = 0;

    // Taking User's choice
    
    while (1)
    {
        printf("\n\n1. Insert Node ");
        printf("\n2. Reverse List ");
        printf("\n3. Find Smallest Node ");
        printf("\n4. Find Sum of Nodes ");
        printf("\n5. Display the List ");
        printf("\n6. Exit \n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number to be inserted: ");
            scanf("%d", &data);
            insertnode_DLL(&head, &lastptr, data);
            display_DLL(head);
            break;
        case 2:
            reverse_DLL(&head);
            display_DLL(head);
            break;
        case 3:
            smallestnode_DLL(&head);
            break;
        case 4:
            sum_DLL(&head);
            break;
        case 5:
            display_DLL(head);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nERROR: ONLY CHOOSE THE OPTIONS LISTED BELOW ");
            break;
        }
    }
}

// Reverses the Doubly Linked List

void reverse_DLL(struct node **head)
{
    if (*head == NULL)
    {
        printf("\nERROR: List is empty\n");
        return;
    }
    struct node *ptr = *head, *temp = NULL;
    // Swapping the next and prev pointers to reverse the order of pointing to nodes
    while (ptr != NULL)
    {
        temp = ptr->prev;
        ptr->prev = ptr->next;
        ptr->next = temp;
        ptr = ptr->prev;
    }
    if (temp != NULL)
    {
        *head = temp->prev;
    }
}

// Finds the smallest node's address and value in the List

void smallestnode_DLL(struct node **head) 
{
    if (*head == NULL)
    {
        printf("\nERROR: List is empty\n");
        return;
    }
    struct node *ptr, *temp;
    ptr = temp = *head;
    // Traversing the list to find value smaller than initially considered and storing the address of that smallest node
    while (ptr != NULL)
    {
        if (ptr->val < temp->val)
        {
            temp = ptr;
        }
        ptr = ptr->next;
    }
    printf("\nSmallest node is: %p with a value: %d", temp, temp->val);
}

// Finds the Sum of nodes in the List

void sum_DLL(struct node **head) 
{
    if (*head == NULL)
    {
        printf("\nERROR: List is empty\n");
        return;
    }
    struct node *ptr = *head;
    int sum = 0;
    // Traversing the list and adding the values of nodes to SUM variable
    while (ptr != NULL)
    {
        sum = sum + ptr->val;
        ptr = ptr->next;
    }
    printf("\nSum of all Nodes: %d", sum);
}

// Inserts a node at the end of List

void insertnode_DLL(struct node **head, struct node **lastptr, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *ptr;
    if (newnode == NULL)
    {
        printf("\nERROR: Memory cannot be allocated\n");
        return;
    }
    newnode->val = data;
    // Creating a New node, linking it and Last node; and making it as *Lastptr (Tail pointer)
    if (*head == NULL)
    {
        newnode->prev = NULL;
        newnode->next = NULL;
        *head = *lastptr = newnode;
    }
    else
    {
        newnode->prev = *lastptr;
        newnode->next = NULL;
        (*lastptr)->next = newnode;
        *lastptr = newnode;
    }
}

// Displays the List

struct node *display_DLL(struct node *head)
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("\nERROR: List is empty\n");
        return head;
    }
    printf("\n\nThe List: \n");
    //Pointing to next node and printing its value in each iteration
    while (ptr != NULL)
    {
        printf("%d <-> ", ptr->val);
        ptr = ptr->next;
    }
    return head;
}