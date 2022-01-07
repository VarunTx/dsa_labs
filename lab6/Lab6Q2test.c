//LAB 6 Q2
//NAME: VARUN TALARI
//ROLL NO: EC20B1041
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
} *head, *current;

void insertFirst(struct node **);
void insertEnd(struct node **);
void deleteFirst(struct node **);
void deleteEnd(struct node **);

struct node *display(struct node *);

int main()
{
    int data = 0, n=0, counter=0, i=0;
    struct node *ptr;
    
    printf("\nEnter the number of Nodes to be in Linked List: ");
    scanf("%d", &n);

    do
    {
        i++;
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        if (new_node == NULL)
        {
            printf("\nERROR: Memory cannot be allocated\n");
            return -1;
        }
        printf("\n\nEnter the value of %d node: ", i);
        scanf("%d", &data);

        new_node->val=data;
        new_node->next=NULL;
        if(head==NULL){
            head=new_node;
            current=new_node;
        }
        else{
            current->next=new_node;
            current=new_node;
            current->next=head;
        }
    }while(counter<=n)
    
    
    display(head);
    // insertFirst(&head);
    // int choice = 0;
    // while (choice!=5)
    // {
    //     printf("\n\n1. Insert Node at First ");
    //     printf("\n2. Insert Node at End ");
    //     printf("\n3. Delete Node at First ");
    //     printf("\n4. Delete Node at End ");
    //     printf("\n5. Exit\n\n");
    //     printf("\nEnter your choice: ");
    //     scanf("%d", &choice);

    //     switch (choice)
    //     {
    //     case 1:
    //         insertFirst(&head);
    //         display(head);
    //         break;
    //     case 2:
    //         insertEnd(&head);
    //         display(head);
    //         break;
    //     case 3:
    //         deleteFirst(&head);
    //         display(head);
    //         break;
    //     case 4:
    //         deleteEnd(&head);
    //         display(head);
    //         break;
    //     case 5:
    //         exit(0);
    //         break;
    //     }
    // }
}

void insertFirst(struct node **head)
{
    int data = 0;
    struct node *ptr = *head, *temp = *head;
    printf("Enter value to be inserted: ");
    scanf("%d", &data);
    struct node *extranode;
    extranode= (struct node *)malloc(sizeof(struct node));
    if (extranode == NULL)
    {
        printf("\nERROR: Memory cannot be allocated\n");
        return;
    }

    extranode->val = data;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = extranode;
    // extranode->next=temp;
    extranode->next = *head;
    *head = extranode;
}

void insertEnd(struct node **head)
{
    int data = 0;
    struct node *ptr = *head, *temp = *head;
    printf("Enter value to be inserted: ");
    scanf("%d", &data);
    struct node *extranode = (struct node *)malloc(sizeof(struct node));
    if (extranode == NULL)
    {
        printf("\nERROR: Memory cannot be allocated\n");
        return;
    }

    extranode->val = data;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = extranode;
    // extranode->next=temp;
    extranode->next = *head;
}

// void deleteFirst(struct node **head)
// {
//     return;
// }

// void deleteEnd(struct node **head)
// {
//     return;
// }

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
    while (ptr!= head)
    {
        printf("-> %d", ptr->val);
        ptr = ptr->next;
    }
    return head;
}