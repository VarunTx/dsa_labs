//LAB 4 QUESTION-1(a)
//Name: Varun Talari
//Roll no: EC20B1041

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define SIZE 50


int main(void)
{
    int m=0, n=0, i, j, C=0;
    printf("\nEnter number of Rows of the Array: ");
    scanf("%d", &m);
    printf("\nEnter number of Columns of the Array: ");         //Reading no. of row & columns
    scanf("%d", &n);
    
    int A[m][n], B[m][n];
    printf("Enter sparse matrix A: \n");
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)                      //Reading sparse A matrix
        {
            scanf("%d",&A[i][j]);
        }
    }

    printf("Enter sparse matrix B: \n");
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)                      //Reading sparse B matrix
        {
            scanf("%d",&B[i][j]);
        }
    }

    int countA=1;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)          //Finding no. of non-zero elements in sparse A matrix
        {
            if(A[i][j]!=0)
            {
                countA++;
            }
        }
    }
    
    int countB=1;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)         //Finding no. of non-zero elements in sparse B matrix
        {
            if(B[i][j]!=0)
            {
                countB++;
            }
        }
    }

    int efficient_matA[3][countA];      //Creating a array efffi..A to convert sparse into 3 row rep
    int x=1;

    efficient_matA[0][0] = m;
    efficient_matA[1][0] = n;
    efficient_matA[2][0] = countA-1;       //Storing no. of row,column and nonzero elem info to first column of A
    
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if (A[i][j] != 0)
            {
                efficient_matA[0][x]=i+1;
                efficient_matA[1][x]=j+1;          //Assigning the nonzero elems to 3 row A matrix 
                efficient_matA[2][x]=A[i][j];
                x++;
            }
        }          
    } 
    
    

    
    
    int efficient_matB[3][countB];          //Storing no. of row,column and nonzero elem info to first column of B
    efficient_matB[0][0] = m;
    efficient_matB[1][0] = n;
    efficient_matB[2][0] = countB-1;
    x=1;
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(B[i][j]!=0)
            {
                efficient_matB[0][x] = i+1;
                efficient_matB[1][x] = j+1;         //Assigning the nonzero elems to 3 row B matrix
                efficient_matB[2][x] = B[i][j];
                x++;
            }
        }
    }

    
    



    printf("\n\t\tTASK 1\n");
    printf(" TASK 1----Efficient matrix for A :\n");
    for(int i=0; i<3; i++)
    {
        for (int j=0; j<countA; j++)
        {
            printf("%d ", *(*(efficient_matA+i)+j));           //Printing the 3 row rep of the sparse A array
        }
        printf("\n");
    }
    printf("\n");
    
    printf(" TASK 1----Efficient matrix for B :\n");
    for(int i=0; i<3; i++)
    {
        for (int j=0; j<countB; j++)
        {
            printf("%d ", *(*(efficient_matB+i)+j));          //Printing the 3 row rep of the sparse B array
        }
        printf("\n");
    }
    printf("\n\n");


    
    
   
    int nonzero = 0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(B[i][j]!=0 && A[i][j]!=0)        //Finding the number of zeroes in both Matrices
            {
                nonzero++;
            }
        }
    } 
    int efficientSum[3][countA+countB-nonzero-1];
    x=1;
    efficientSum[0][0] = m;
    efficientSum[1][0] = n;                         //creating another 3 row Array "efficientSum" to store A+B
    efficientSum[2][0] = countA+countB-nonzero-2;       //Storing no. of row,column and nonzero elem info to first column of Sum

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)                              //Logic for sum of matrices
        {
            if(A[i][j]!=0 && B[i][j]!=0)
            {
                efficientSum[0][x] = i+1;
                efficientSum[1][x] = j+1;                   //If position of nonzero elements in arrays A & B
                efficientSum[2][x] = A[i][j] + B[i][j];         //are same, then we just add their value
                x++;
            }
            else if(A[i][j]!=0)
            {
                efficientSum[0][x] = i+1;
                efficientSum[1][x] = j+1;                   //If only elem of array A is nonzero at that position then
                efficientSum[2][x] = A[i][j];                   //we assignplace it in separate column
                x++;
            }
            else if(B[i][j]!=0)
            {
                efficientSum[0][x] = i+1;
                efficientSum[1][x] = j+1;                   //If only elem of array B is nonzero at that position then
                efficientSum[2][x] = B[i][j];                   //we assign it in separate column
                x++;
            }
        }
    }

    printf("Added RESULT EFFICIENT MATRIX :\n");
    //displayArray (efficientSum, 3, countA+countB-check-1);
    for(int i=0; i<3; i++)
    {
        for (int j=0; j<countA+countB-nonzero-1; j++)
        {
            printf("%d ", *(*(efficientSum+i)+j));          //Printing the elements of the final Array, "Sum"
        }                                                       //after adding matrices A & B in 3 row rep
        printf("\n");
    }

    printf("\n\n\n");
    return 0;
}