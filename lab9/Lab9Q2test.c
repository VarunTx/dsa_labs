//LAB 9 Q2 (Stack using two Queues)
//NAME: VARUN TALARI
//ROLL NO: EC20B1041
#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};

struct stack {
    struct node* q1;
    struct node* q2;
    struct node* tempq;
};

void push(struct stack *s, int data);
void pop(struct stack *s);
void top(struct stack *s);
void displaystack(struct stack *s);

void enqueue(struct node **front, int data);
int dequeue(struct node **front);
int peek(struct stack *s, struct node **front);

int main()
{
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->q1=NULL;
    s->q2=NULL;
    s->tempq=NULL;
    
    int data = 0, choice = 0;

    // Taking User's choice

    while (1)
    {
        printf("\n\n1. Push ");
        printf("\n2. Pop ");
        printf("\n3. Peek Top ");
        printf("\n4. Display queue and Exit program ");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter number to be pushed: ");
            scanf("%d", &data);
            push(s, data);
            printf("Pushed %d now ", data);
            top(s);
            break;
        case 2:
            pop(s);
            printf("\nNow ");          
            top(s);
            break;
        case 3:
            top(s);
            break;
        case 4:
            displaystack(s);
            exit(0);
            break;
        default:
            printf("\n\nERROR: ONLY CHOOSE THE OPTIONS LISTED BELOW ");
            break;
        }
    }
    return 0;
}


void push(struct stack *s, int data)
{
    int temp,t;
    enqueue(&s->q2, data);
    while(s->q1!=NULL){
        temp=dequeue(&s->q1);
        enqueue(&s->q2,temp);
    }
    s->tempq=s->q1;
    s->q1=s->q2;
    s->q2=s->tempq;
}
void pop(struct stack *s)
{
    int temp;
    if(s->q1==NULL){
        printf("\n\nERROR: Stack is empty");
        return;
    }
    else{
        temp=dequeue(&s->q1);
        printf("The Popped element from stack is: %d", temp);
    }
}

void top(struct stack *s)
{
    int temp;
    if(s->q1==NULL){
        printf("\n\nERROR: Stack is empty");
        return;
    }
    else{
        temp=peek(s, &s->q1);
        printf("The top element in Stack: %d", temp);
    }
}

void displaystack(struct stack *s)
{
    if(s->q1==NULL){
        printf("\n\nStack is Empty\n\n");
        return;
    }
    struct stack *extra=(struct stack *)malloc(sizeof(struct stack));
    extra->tempq=s->q1;
        printf("\nThe final Stack is: \n");
    while(extra->tempq!=NULL){
        printf("%d ", peek(s, &extra->tempq));
        dequeue(&extra->tempq);
    }
    printf("\n\n");
}

void enqueue(struct node **front, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("\nERROR: Memory cannot be allocated\n");
        return;
    }
    struct node *last=*front;
    newnode->val=data;
    if(*front==NULL){
        newnode->next=NULL;
        *front=newnode;
    }
    else{
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=newnode;
        newnode->next=NULL;
    }
}
int dequeue(struct node **front)
{
    int temp;
    struct node *ptr=*front;
    temp=ptr->val;
    *front=ptr->next;
    ptr->next=NULL;
    free(ptr);
    return temp;
}

int peek(struct stack *s, struct node **front)
{
    int temp;
    temp=(*front)->val;
    return temp;
}