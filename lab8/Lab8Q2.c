//LAB 8 Q2 (Polynomial sort inserting)
//NAME: VARUN TALARI
//ROLL NO: EC20B1041
#include <stdio.h>
#include <stdlib.h>

struct poly
{
    float coeff;
    int power;
    struct poly *next;
} *head = NULL;

void arrangePoly(struct poly **, float , int );
void insert_case1(float , int );
void insert_case2(struct poly **, float , int );
int checkrepeat(struct poly **, int );
struct poly *display(struct poly *);

int main()
{
    float co;
    int pow, check = 0;
    int choice = 0;

    // Taking User's choice

    while (1)
    {
        printf("\n\n1. Insert a Polynomial term ");
        printf("\n2. Display Polynomial ");
        printf("\n3. Exit \n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n\nEnter Coefficient of term: ");
            scanf("%f", &co);
            printf("Enter Power of term: ");
            scanf("%d", &pow);
            check = checkrepeat(&head, pow);
            if (check == 1)
            {
                printf("\nERROR: The Entered power of x already exists, try again ");
                break;
            }
            else
            {
                arrangePoly(&head, co, pow);
                display(head);
                break;
            }
        case 2:
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

// Arranges polynomial terms in descending order of exponents of the variable

void arrangePoly(struct poly **head, float co, int pow)
{
    struct poly *newnode = (struct poly *)malloc(sizeof(struct poly));
    struct poly *ptr = *head, *preptr = NULL;
    if (newnode == NULL)
    {
        printf("\nERROR: Memory cannot be allocated\n");
        return;
    }
    // Passing to appropriate Insert cases based on exponent of the term to be inserted
    if (*head == NULL)
    {
        insert_case1(co, pow);
        return;
    }
    else if (pow > (*head)->power)
    {
        insert_case1(co, pow);
        return;
    }
    else
    {
        while (ptr->next != NULL && pow < ptr->next->power)
        {
            ptr = ptr->next;
        }
        insert_case2(&ptr, co, pow);
    }
}

// Inserts a term/node before head     

void insert_case1(float co, int pow)
{
    struct poly *newnode = (struct poly *)malloc(sizeof(struct poly));
    if (newnode == NULL)
    {
        printf("\nERROR: Memory cannot be allocated\n");
        return;
    }
    // Linking newnode and head, and then updates the head to point to newnode
    newnode->coeff = co;
    newnode->power = pow;

    newnode->next = head;
    head = newnode;
}

// Inserts a term/node after the specified term/node

void insert_case2(struct poly **ptr, float co, int pow)
{
    struct poly *newnode = (struct poly *)malloc(sizeof(struct poly));
    if (newnode == NULL)
    {
        printf("\nERROR: Memory cannot be allocated\n");
        return;
    }
    // Linking newnode to prev node, and making newnode point to next of prevnode
    newnode->coeff = co;
    newnode->power = pow;

    newnode->next = (*ptr)->next;
    (*ptr)->next = newnode;
}

// Checks if the exponent of term to be inserted, is already in the polynomial or not

int checkrepeat(struct poly **head, int pow)
{
    int flag = 0;
    struct poly *ptr = *head;
    if (*head == NULL)
    {
        return 0;
    }
    // Traversing list to check if exponent is present or not
    while (ptr != NULL)
    {
        if (ptr->power == pow)
        {
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (flag == 1)
    {
        return 1;
    }
    return 0;
}

// Displays the entire polynomial

struct poly *display(struct poly *head)
{
    struct poly *ptr = head;
    if (head == NULL)
    {
        printf("\nERROR: List is empty\n");
        return head;
    }
    printf("\n\nThe List: \n");
    // Pointing to next node and printing its value in each iteration
    while (ptr != NULL)
    {
        printf("%.2f", ptr->coeff);
        if (ptr->power != 0 && ptr->power != 1)
        {
            printf("x^%d", ptr->power);
            if (ptr->next)
            {
                printf(" + ");
            }
        }
        else if (ptr->power == 1)
        {
            printf("x");
            if (ptr->next)
            {
                printf(" + ");
            }
        }
        else if (ptr->power == 0)
        {
            printf("");
        }
        ptr = ptr->next;
    }
    return head;
}
