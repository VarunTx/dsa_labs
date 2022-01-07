#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next; // Self referential Structure
} *start = NULL;

void createLL(int n);
struct node *displayLL(struct node *);

struct node *insert_Beginning(struct node *);
struct node *insert_End(struct node *);
struct node *insert_Before(struct node *);
struct node *insert_After(struct node *);

struct node *delete_Beginning(struct node *);
struct node *delete_End(struct node *);
struct node *delete_Before(struct node *);
struct node *delete_After(struct node *);
struct node *countRepeat(struct node *);
struct node *addressNode(struct node *);
struct node *multiplyNode(struct node *);

int main()
{
    int n, i;
    printf("\nEnter the number of Nodes to be in Linked List: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("ERROR: Input should be Positive integers greater than Zero");
    }
    int A[n];
    printf("\nEnter values for Linked List: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    createLL(A, n);
        
        
        
        
        
        
        // struct node *first, *new_node;
        // first = (struct node *)malloc(sizeof(struct node));
        // struct node *ptr;
        // if (first == NULL)
        // {
        //     printf("ERROR: Memory cannot be allocated:\n");
        // }
        // else
        // {
        //     first->val = A[0];
        //     first->next = NULL;
        //     start = first;
        //     ptr=start;
        //     for (int i = 1; i < n; i++)
        //     {
        //         new_node = (struct node *)malloc(sizeof(struct node));
        //         if (new_node == NULL)
        //         {
        //             printf("ERROR: Memory cannot be allocated\n");
        //             break;
        //         }
        //         else
        //         {
        //             new_node->val = A[i];
        //             new_node->next = NULL;
        //             start->next = new_node; // The next part of First node gets linked with address of Second node data
        //             start = new_node;       //Making the pointer now point to the newly created node
        //         }
        //     }
    
        
        displayLL(start);

        insert_Beginning(start);
        // insert_End(start);
        // insert_Before(start);
        // insert_After(start);

        // delete_Beginning(start);
        // delete_End(start);
        // delete_Before(start);
        // delete_After(start);

        countRepeat(start);
        addressNode(start);
        multiplyNode(start);
        /*displayLL(start);*/
        
    return 0;
}

void createLL(int n)       //CHANGED
{
    struct node *temp, *new_node, *first_node;
    first_node = (struct node *)malloc(sizeof(struct node));
    struct node *ptr;
    if (first_node == NULL)
    {
        printf("ERROR: Memory cannot be allocated:\n");
        return;
    }
    else
    {
        first_node->val = A[0];
        first_node->next = NULL;
        start = first_node;
        ptr=start;
        for (int i = 1; i < n; i++)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            if (new_node == NULL)
            {
                printf("ERROR: Memory cannot be allocated\n");
                break;
            }
            else
            {
                new_node->val = A[i];
                new_node->next = NULL;
                start->next = new_node; // The next part of First node gets linked with address of Second node data
                start = new_node;       //Making the pointer now point to the newly created node
            }
        }
    }
    // return start;
}

struct node *displayLL(struct node *start) // CHANGED
{
    struct node *ptr;
    ptr = start;
    if (start == NULL)
        printf("\nList is empty\n");
    else{
        while (ptr != NULL)
        {
            printf("%d ", ptr->val);
            ptr = ptr->next;
        }
    }
    return start;
}

struct node *countRepeat(struct node *start)           //CHANGED
{
    int count = 0, NUM;
    struct node *counter;
    counter = start;
    printf("\n\nEnter a number to count its repetation in LL: ");
    scanf("%d", &NUM);
    while (counter != NULL)
    {
        if (counter->val == NUM)
        {
            count++;
        }
        counter = counter->next;
    }
    if (count == 0)
    {
        printf("ERROR: The Entered number is not present the Linked List\n");
    }
    else
    {
        printf("\n\nThe Entered Number repeated %d time(s) in the Linked List\n", count);
    }
    return start;
}

struct node *addressNode(struct node *start)        //CHANGED       
{
    int KEY = 0, check = 0;
    struct node *addr;
    addr = start;
    printf("\n\nEnter a number to display its address from LL: ");
    scanf("%d", &KEY);
    while (addr != NULL)
    {
        if (addr->val == KEY)
        {
            check = 1;
            printf("\nThe Address of the node which contains this number is: %p", &addr);
            break;
        }
        addr = addr->next;
    }
    if (check == 0)
    {
        printf("\nERROR: The entered number is not present in the Linked List");
    }
    return start;
}

struct node *multiplyNode(struct node *start)   // CHANGED
{
    int CONST = 0;
    struct node *ptr;
    ptr = start;
    printf("\n\nEnter a number which should be multiplied to elements in LL: ");
    scanf("%d", &CONST);
    while (ptr != NULL)
    {
        ptr->val = CONST * (ptr->val);
        ptr = ptr->next;
    }
    printf("\n\nThe LL after multiplying all elements with %d: \n", CONST);
    displayLL(start);
    return start;
}

struct node *insert_Beginning(struct node *start)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nERROR: Memory cannot be Allocated");
    }
    else
    {
        int data;
    struct node* temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &data);
    temp->val = data;
  
    // Pointer of temp will be
    // assigned to start
    temp->next = start;
    start = temp;
    }
    insert_End(start);
    return start;
}

struct node *insert_End(struct node *start)
{
    struct node *new_node2;
    new_node2 = (struct node *)malloc(sizeof(struct node));
    if (new_node2 == NULL)
    {
        printf("\nERROR: Memory cannot be Allocated");
    }
    else
    {
    int data;
    struct node *temp, *head;
    temp = (struct node *)malloc(sizeof(struct node));
  
    // Enter the number
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &data);
  
    // Changes links
    temp->next = 0;
    temp->val = data;
    head = start;
    while (head->next != NULL) {
        head = head->next;
    }
    head->next = temp;
    }
    insert_Before(start);
    return start;
}

struct node *insert_Before(struct node *start)
{
    struct node *new_node3, *ptr, *preptr, *print, *t;
    new_node3 = (struct node *)malloc(sizeof(struct node));
    int DATA = 0, value, flag = 0;
    if (new_node3 == NULL)
    {
        printf("\nERROR: Memory cannot be Allocated");
    }
    else
    {
        printf("\n\nEnter the value which you wish to insert before specified location: ");
        scanf("%d", &DATA);
        printf("\n\nEnter the element before which you wish to insert %d: ", DATA);
        scanf("%d", &value);
    
            int checker=0;
            struct node *check= start;
            while(check!=NULL){
                if(check->val==value){
                    checker=1;
                }
                check=check->next;
            }
            if(checker==0){
                printf("ERROR:The Entered element is not in the list")
                //nextfunctionname
            }
            
            
            while
            
            new_node3->val = DATA;
            new_node3->next = NULL;
            ptr = start;
            while (ptr->val != value)
            {
                preptr = ptr;
                ptr = ptr->next;
            }
            preptr->next = new_node3;
            new_node3->next = ptr;

            printf("After inserting an element before Specified Node: \n");
            print = start;
            while (print != NULL)
            {
                printf("%d ", print->val);
                print = print->next;
            }
    }
    insert_After(start);
    return (start);
}

struct node *insert_After(struct node *start)
{
    struct node *new_node4, *ptr, *print, *postptr, *t;
    new_node4 = (struct node *)malloc(sizeof(struct node));
    if (new_node4 == NULL)
    {
        printf("\nERROR: Memory cannot be Allocated");
    }
    else
    {
        int DATA, value, flag = 0;
        printf("\n\nEnter the value which you wish to insert after specified location: ");
        scanf("%d", &DATA);

        printf("\nEnter the element after which you wish to insert: ");
        scanf("%d", &value);
    
            new_node4->val = DATA;
            new_node4->next = NULL;
            ptr = start;
            while (ptr->val != value)
            {
                postptr = ptr->next->next;
                ptr = ptr->next;
            }
            // Inserting an element between 2 nodes,(after specified location)
            ptr->next = new_node4;     // This node stores address of the newnode
            new_node4->next = postptr; // newnode stores the address of next node
            printf("\nAfter inserting an element after specified location\n");
            print = start;
            while (print != NULL)
            {
                printf("%d ", print->val);
                print = print->next;
            }

    }
    delete_Beginning(start);
    return start;
}

struct node *delete_Beginning(struct node *start)
{
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->next;
        free(temp);
    delete_End(start);
    return (start);
    }
}

struct node *delete_End(struct node *start)
{
    struct node *temp=start;
    struct node *t;
    if(start->next==NULL)
    {
        free(start);
        start=NULL;
    }
    else
    {
        while(temp->next != NULL)
        {
            t=temp;
            temp=temp->next;
        }
        free(t->next);
        t->next=NULL;
    }    
  return start;
}

struct node *delete_Before(struct node *start)
{
    int value, flag = 0;
    struct node *ptr, *t;
    struct node *preptr = NULL;
    struct node *preptr2 = NULL;
    printf("\n\nEnter the element before which you wish to delete\n");
    scanf("%d", &value);

        ptr = start;
        while (ptr->val != value)
        {
            preptr2 = preptr;
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr2->next = ptr; // Creating the link between left and right nodes of the specific pos which we are deleting
        struct node *print;
        printf("\nAfter deleting an element before specified location\n");
        print = start;
        while (print != NULL)
        {
            printf("%d\n", print->val);
            print = print->next;
        }
    
    
    delete_After(start);
    return (start);
}

struct node *delete_After(struct node *start)
{
    int value, flag = 0;
    struct node *ptr, *t;
    struct node *postptr;
    printf("\n\nEnter the element after which you wish to delete: ");
    scanf("%d", &value);

    
        ptr = start;
        while (ptr->val != value)
        {
            postptr = ptr->next->next;
            ptr = ptr->next;
        }
        ptr->next = postptr->next; // Deleting the particular node
        struct node *print;
        printf("\nAfter deleting an element after a specified location\n");
        print = start;
        while (print != NULL)
        {
            printf("%d\n", print->val);
            print = print->next;
        }
    
    return (start);
}