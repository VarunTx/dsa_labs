//LAB 3 Q2
//Name: Varun Talari
//Roll no: EC20B1041

#include<stdio.h>
#define SIZE 100

int main()
{
    int n;
    printf("\nEnter Size of the 2D Array: ");	//Reading Size of array A[][]
	scanf("%d", &n);

	int  B[SIZE], A[n][n];				    //Declaring arrays

	printf("\nEnter the 2D Array elements: \n");		
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)             //Reading A[] array elements
        {
            scanf("%d", &A[i][j]);
        }
    } 

    int t;
    printf("\nEnter '1' for displaying Lower Triangle array elements (or)");
    printf("\nEnter '2' for displaying Upper Triangle array elements: \n ");
	scanf("%d", &t);            //Asking User for the type of solution
    
    static int u=0;
    if(t==1)
    {
        for(int i=0; i<n; i++)
        {
             for(int j=0; j<n; j++)
            {
                if (i>=j)           //Using condition of Lower Triangular matrix (row>col)
                {                   //to copy elements in a 1D array
                    B[u]=A[i][j];
                    u++;
                }

            } 
        }
    }
    if(t==2)
    {
        for(int i=0; i<n; i++)
        {
             for(int j=0; j<n; j++)
            {
                if (j>=i)           //Using condition of Upper Triangular matrix (col>row)
                {                   //to copy elements in a 1D array
                    B[u]=A[i][j];
                    u++;
                }

            } 
        }
    }
    
    printf("\n\nThe corresponding 1D matrix is:");      //Printing 1D array
    for(int i=0; i<u; i++)
        printf("\t\n%d", B[i]);

    printf("\n\n\n");
    return 0;
}