//LAB 4 QUESTION-2
//Name: Varun Talari
//Roll no: EC20B1041

#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

int A[50][50], n;                               //Creating A array as global, to reduce usage of pointers to access "A" in function

double cal_Det(int A[50][50], int n)
{
    int sign, Cofac[50], det=0, B[50][50];
    int i, k, l, t; 
    

    if (n == 2)
    {
        det = 0;                                            //If Array size is 2 then we are multiplying and adding
        det = (A[1][1] * A[2][2]) - (A[1][2] * A[2][1]);        //diagonals to get det
        return (det);
    }
                                                    
    else
    {
        for (i=1; i <= n; i++)
        {
            int r=1, s=1;
            for (k=1; k<=n; k++)                   //Making Co-factor matrix corresponding to the array element
            {
                for (l=1; l<=n; l++)
                {
                    if (k!=1 && l!=i)               //Not considering the elements in the same row and column
                    {
                        B[r][s] = A[k][l];
                        s++;
                        if ( s>n-1)                 
                        {
                            r++;                    //Increasing Row by 1 and again consider the columns from 1
                            s=1;
                        }
                    }
                }
            }


            for (t=1, sign=1; t<=(1+i); t++)            //Negative signs in alternating places for the co-factor
                sign= (-1)*sign;

            Cofac[i]= sign*cal_Det(B, n-1);             //Getting the det of the cofac matrix
        }

        
        for (i=1, det=0; i<=n; i++)
        {
            det= det+(A[1][i] * Cofac[i]);              //Multiplying the element to its co-factor matrix and 
        }                                                   //summing up to get Determinant value

        return (det);
    }
}

int main()
{
    int i, j;

    printf("Enter size of the matrix A: ");
    scanf("%d", &n);

    printf("Enter elements of the matrix A : \n");
    for (i=1; i<=n; i++)                                     //Reading Array elements
    {
        for (j=1; j<=n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
                                      
    printf("The determinant is %f\n", cal_Det(A, n));    //Calling the Function to find the determinant of the matrix       


    int sum = 0;
    if (cal_Det(A, n) == 0)
    {
        for (i=1; i<=n; i++)        //Adding non-diagonal elements if determinant is zero
        {
            for (j=1; j<=n; j++)
            {
                if (i!=j)           //Condition: The non-diagonal elements have different row & column indices
                {
                    sum=sum+A[i][j];
                }
            }
        }
    }

    else
    {
        for (i=1; i<=n; i++)
        {
            for (j=1; j<=n; j++)         //Adding Diagonal elements if Determinant is nonzero
            {
                if (i==j)                   //Condition: The diagonal elements have same row & column indices
                {
                    sum=sum+A[i][j];
                }
            }
        }
    }

    printf("The Sum according to Det is : %d\n", sum);        //Printing the Sum

    return 0;
}
