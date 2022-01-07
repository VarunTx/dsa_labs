//LAB 6 Q2
//NAME: VARUN TALARI
//ROLL NO: EC20B1041
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
} * head;

void insertFirst(struct node **);
void insertEnd(struct node **);
void deleteFirst(struct node **);
void deleteEnd(struct node **);
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
    ptr->next = head;

    int choice = 0;

    // Taking User's choice

    while (1)
    {
        printf("\n\n1. Insert Node at First ");
        printf("\n2. Insert Node at End ");
        printf("\n3. Delete Node at First ");
        printf("\n4. Delete Node at End ");
        printf("\n5. Display List ");
        printf("\n6. Exit\n\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertFirst(&head);
            display(head);
            break;
        case 2:
            insertEnd(&head);
            display(head);
            break;
        case 3:
            deleteFirst(&head);
            display(head);
            break;
        case 4:
            deleteEnd(&head);
            display(head);
            break;
        case 5:
            display(head);
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

// Inserts a Node at Beginning of List

void insertFirst(struct node **head)
{
    int data = 0;
    struct node *ptr = *head, *temp = *head;
    printf("Enter value to be inserted: ");
    scanf("%d", &data);
    struct node *extranode;
    extranode = (struct node *)malloc(sizeof(struct node));
    if (extranode == NULL)
    {
        printf("\nERROR: Memory cannot be allocated\n");
        return;
    }
    // Linking the Inserted and last nodes, making it point to first node and updating the *Head
    extranode->val = data;
    while (ptr->next != *head)
    {
        ptr = ptr->next;
    }
    extranode->next = NULL;
    extranode->next = *head;
    ptr->next = extranode;
    *head = extranode;
}

// Inserts a Node at the End of List

void insertEnd(struct node **head)
{
    int data = 0;
    struct node *ptr = *head;
    printf("Enter value to be inserted: ");
    scanf("%d", &data);
    struct node *extranode = (struct node *)malloc(sizeof(struct node));
    if (extranode == NULL)
    {
        printf("\nERROR: Memory cannot be allocated\n");
        return;
    }
    // Linking the inserted and last nodes, and making it point to *Head
    extranode->val = data;
    while (ptr->next != *head)
    {
        ptr = ptr->next;
    }
    extranode->next = NULL;
    extranode->next = *head;
    ptr->next = extranode;
}

// Deletes the Beginning node from List

void deleteFirst(struct node **head)
{
    if (*head == NULL)
    {
        printf("\nERROR: List is empty\n");
        return;
    }

    struct node *ptr = *head, *temp = *head;
    // Making the last node point to Second node and updating *Head
    while (ptr->next != *head)
    {
        ptr = ptr->next;
    }
    ptr->next = temp->next;
    *head = temp->next;
    temp->next = NULL;
    free(temp);
}

// Deletes the Last node from List

void deleteEnd(struct node **head)
{
    if (*head == NULL)
    {
        printf("\nERROR: List is empty\n");
        return;
    }

    struct node *ptr = *head, *prevptr;
    // Making the Last but one node to point to *Head
    while (ptr->next != *head)
    {
        prevptr = ptr;
        ptr = ptr->next;
    }
    prevptr->next = *head;
    ptr->next = NULL;
    free(ptr);
}

//Displays the List

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
    while (ptr->next != head)
    {
        printf("%d \n", ptr->val);
        ptr = ptr->next;
    }
    printf("%d", ptr->val);
    return head;
}