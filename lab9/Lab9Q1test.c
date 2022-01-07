//LAB 9 Q1 (Queue using two Stacks)
//NAME: VARUN TALARI
//ROLL NO: EC20B1041
#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
}*top1=NULL, *top2=NULL;

void push(int data);
void pop();
void displayLL();

void main()
{
    int data = 0, choice = 0;
    while (1)
    {
        printf("\n1. Push ");
        printf("\n2. pop ");
        printf("\n3. Exit \n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number to be inserted: ");
            scanf("%d", &data);
            push(data);
            displayLL();
            break;
        case 2:
            pop();
            displayLL();
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

void push(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("\nERROR: Memory cannot be allocated\n");
        return;
    }
    newnode->val=data;
    if(top1==NULL){
        newnode->next=NULL;
        top1=newnode;
    }
    else{
        newnode->next=top1;
        top1=newnode;
    }
}

void pop()
{
    if(top1==NULL){
        printf("\nERROR: Underflow, Stack is empty\n");
        return;
    }
    struct node *ptr=top1;
    top1=top1->next;
    ptr->next=NULL;
    free(ptr);
}

void displayLL()
{
    struct node *ptr;
    ptr = top1;
    if (top1 == NULL)
        printf("\nStack is empty\n");
    else{
        while (ptr != NULL)
        {
            printf("%d  ", ptr->val);
            ptr = ptr->next;
        }
    }
}