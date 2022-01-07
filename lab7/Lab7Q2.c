//LAB 7 Q2 (CIRCULAR DOUBLY LINKED LIST)
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

void insertFirst_CDLL(struct node **, struct node **, int);
void insertEnd_CDLL(struct node **, struct node **, int);
void deleteFirst_CDLL(struct node **, struct node **);
void deleteEnd_CDLL(struct node **);
struct node *display_CDLL(struct node *);

int main()
{
    int choice = 0, data = 0;

    // Taking User's choice

    while (1)
    {
        printf("\n\n1. Insert Node at First ");
        printf("\n2. Insert Node at End ");
        printf("\n3. Delete Node at First ");
        printf("\n4. Delete Node at End ");
        printf("\n5. Display List ");
        printf("\n6. Exit \n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number to be inserted: ");
            scanf("%d", &data);
            insertFirst_CDLL(&head, &lastptr, data);
            display_CDLL(head);
            break;
        case 2:
            printf("Enter number to be inserted: ");
            scanf("%d", &data);
            insertEnd_CDLL(&head, &lastptr, data);
            display_CDLL(head);
            break;
        case 3:
            deleteFirst_CDLL(&head, &lastptr);
            display_CDLL(head);
            break;
        case 4:
            deleteEnd_CDLL(&head);
            display_CDLL(head);
            break;
        case 5:
            display_CDLL(head);
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

// Inserts a node at the Beginning of List

void insertFirst_CDLL(struct node **head, struct node **lastptr, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = *head;
    *lastptr = *head;
    if (newnode == NULL)
    {
        printf("\nERROR: Memory cannot be allocated\n");
        return;
    }
    newnode->val = data;
    // Linking the Inserted and last nodes; and making it's next, point to initial First node. Also updating the *head
    if (*head == NULL)
    {
        *head = *lastptr = newnode;
        newnode->prev = NULL;
        newnode->next = *head;
    }
    else
    {
        while ((*lastptr)->next != *head)
        {
            *lastptr = (*lastptr)->next;
        }
        newnode->prev = *lastptr;
        newnode->next = *head;
        (*lastptr)->next = newnode;
        *head = newnode;
    }
}

// Inserts a node at the End of List

void insertEnd_CDLL(struct node **head, struct node **lastptr, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = *head;
    *lastptr = *head;
    if (newnode == NULL)
    {
        printf("\nERROR: Memory cannot be allocated\n");
        return;
    }
    newnode->val = data;
    // Linking the Inserted and Last nodes; and making it's next pointer, point to *head
    if (*head == NULL)
    {
        *head = *lastptr = newnode;
        newnode->prev = NULL;
        newnode->next = *head;
    }
    else
    {
        while ((*lastptr)->next != *head)
        {
            *lastptr = (*lastptr)->next;
        }
        newnode->prev = *lastptr;
        newnode->next = *head;
        (*lastptr)->next = newnode;
        (*lastptr)=newnode;
        (*head)->prev=*lastptr;
    }
}

// Deletes a node from the Beginning of List

void deleteFirst_CDLL(struct node **head, struct node **lastptr)
{
    if (*head == NULL)
    {
        printf("\nERROR: List is empty\n");
        return;
    }
    
    struct node *temp = *head;
    *lastptr = *head;
    // Linking Last and the node after first node; and removing connections of First node. Also updating *head
    while ((*lastptr)->next != *head)
    {
        *lastptr = (*lastptr)->next;
    }
    if ((*head)->next == *head)
    {
        *head = NULL;
        free(*head);
        return;
    }
    else
    {
        (*lastptr)->next = temp->next;
        temp->next->prev = *lastptr;
        *head = temp->next;
        temp->prev = NULL;
        temp->next = NULL;
        free(temp);
    }
}

// Deletes a node from the End of List

void deleteEnd_CDLL(struct node **head)
{
    if (*head == NULL)
    {
        printf("\nERROR: List is empty\n");
        return;
    }
    
    struct node *ptr = *head, *preptr = NULL;
    // Linking last but one node and First node; and removing connections of Last node
    while (ptr->next != *head)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if ((*head)->next == *head)
    {
        *head= NULL;
        free(*head);
        return;
    }
    else
    {
        preptr->next = *head;
        (*head)->prev = preptr;
        ptr->prev = NULL;
        ptr->next = NULL;
        free(ptr);
    }
}

// Displays the List

struct node *display_CDLL(struct node *head)
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
    while (ptr->next != head)
    {
        printf("%d \n", ptr->val);
        ptr = ptr->next;
    }
    printf("%d", ptr->val);
    return head;
}