//LAB 3 Q1
//Name: Varun Talari
//Roll no: EC20B1041

#include<stdio.h>
#define SIZE 100

int main()
{
    int m, n;
    printf("\nEnter no. of Rows: ");
	scanf("%d", &m);                        //Reading size of Rows and Columns
    printf("Enter no. of Columns: ");
	scanf("%d", &n);

    int A[SIZE][SIZE];

    printf("Enter the Array Elements:\n");              //Declaring & reading Array
    for(int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }  
        //FOR ENCRYPTING ARRAY
    for(int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)         //Incrementing the boundary elements by i+1 
        {
            if (i==0 || i==m-1){
                A[i][j]= A[i][j]+i+1;
            }
        }
    }
    for(int i=1; i<m-1; i++)    
    {
        A[i][0]= A[i][0]+i+1;      //Incrementing the rest of boundary elements by i+1
        A[i][n-1]= A[i][n-1]+i+1;

    }
 
    for(int i=1; i<m-1; i++)        //Decrementing Inner elements of array by j
    {
        for(int j=1; j<n-1; j++)
        {
            A[i][j]= A[i][j]-j;
        }
    }
    printf("\nThe Encrypted matrix will be:\n");       
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)          //Printing Encrypted Array
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    
    
            //FOR DECRYPTING ARRAY, we performing reverse operations
    for(int i=0; i<m; i++)          
    {
        for(int j=0; j<n; j++)          //Decrementing the boundary elements by i+1
        {
            if(i==0 || i==m-1){
                A[i][j]= A[i][j]-i-1;
            }
        }
    }
    for(int i=1; i<m-1; i++)
    {
        A[i][0]= A[i][0]-i-1;          //Decrementing the rest of boundary elements by i+1
        A[i][n-1]= A[i][n-1]-i-1;
    }
    //inner
    for(int i=1; i<m-1; i++)
    {
        for(int j=1; j<n-1; j++)        //Incrementing Inner elements of array by j
        {
            A[i][j]= A[i][j]+j;
        }
    }

    printf("\nThe Decrypted matrix will be:\n");
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)          //Printing Decrypted Array
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}