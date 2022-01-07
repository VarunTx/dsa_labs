//LAB 4 QUESTION-1(b)
//Name: Varun Talari
//Roll no: EC20B1041

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define SIZE 50

struct effici{
    int rowOne[SIZE];
    int rowTwo[SIZE];       //Creating struct with 3 arrays as elements
    int value[SIZE];
};


int main(void)
{
    int m=0, n=0, i, j;
    printf("\nEnter number of Rows of the Array: ");
    scanf("%d", &m);
    printf("\nEnter number of Columns of the Array: ");         //Reading no. of row & columns
    scanf("%d", &n);
    
    int matA[m][n], matB[m][n];
    printf("Enter sparse matrix A: \n");
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)                      //Reading sparse A matrix
        {
            scanf("%d",&matA[i][j]);
        }
    }

    printf("Enter sparse matrix B: \n");
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)                  //Reading sparse B matrix
        {
            scanf("%d",&matB[i][j]);
        }
    }

    int countA=1;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)           //Finding no. of non-zero elements in sparse A matrix
        {
            if(matA[i][j]!=0)
            {
                countA++;
            }
        }
    }
    
    int countB=1;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)          //Finding no. of non-zero elements in sparse B matrix
        {
            if(matB[i][j]!=0)
            {
                countB++;
            }
        }
    }

    struct effici A;
    struct effici B;                //Creating three variables of type struct effici to rep 3 rows
    struct effici Result;


    int x=1;

    A.rowOne[0] = m;
    A.rowTwo[0] = n;                //Assigning required data(rows,columns,value) in the first column 
    A.value[0] = countA-1;          //In Struct effici A
    
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if (matA[i][j] != 0)
            {
                A.rowOne[x]=i+1;            //Assigning the non-zero elements to respective struct effici A 
                A.rowTwo[x]=j+1;
                A.value[x]=matA[i][j];
                x++;
            }
        }          
    } 
    
    
    
    
    B.rowOne[0] = m;
    B.rowTwo[0] = n;                   //Assigning required data(rows,columns,value) in the first column 
    B.value[0] = countB-1;             //In Struct effici B
    x=1;
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(matB[i][j]!=0)
            {
                B.rowOne[x] = i+1;          //Assigning the non-zero elements to respective struct effici A   
                B.rowTwo[x] = j+1;
                B.value[x] = matB[i][j];
                x++;
            }
        }
    }

    
    

    printf("\n\t\tTASK 1\n");
    printf(" TASK 1----Efficient matrix for A :\n");
    for(int i=0; i<countA; i++){
        printf("%d ", A.rowOne[i]);
    }
    printf("\n");
    for(int i=0; i<countA; i++){            //Printing the struct efficient A and its elements  
        printf("%d ", A.rowTwo[i]);
    }
    printf("\n");
    for(int i=0; i<countA; i++){
        printf("%d ", A.value[i]);
    }
    
    
    printf("\n\n");
    
    printf(" TASK 1----Efficient matrix for B :\n");
    for(int i=0; i<countB; i++){
        printf("%d ", B.rowOne[i]);
    }
    printf("\n");
    for(int i=0; i<countB; i++){
        printf("%d ", B.rowTwo[i]);         //Printing the struct efficient A and its elements 
    }
    printf("\n");
    for(int i=0; i<countB; i++){
        printf("%d ", B.value[i]);
    }
    
    
    printf("\n\n");


    
   
    int zeroElem = 0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)                  //Finding the number of zeroes in both Matrices
        {
            if(matB[i][j]!=0 && matA[i][j]!=0)      
            {
                zeroElem++;
            }
        }
    } 

    x=1;
    Result.rowOne[0] = m;
    Result.rowTwo[0] = n;                           //Creating "result" of struct effici type and  
    Result.value[0] = countA+countB-zeroElem-2;     //Assigning required data(rows,columns,value) in First column

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)                      //Logic for sum of matrices
        {
            if(matA[i][j]!=0 && matB[i][j]!=0)
            {
                Result.rowOne[x] = i+1;
                Result.rowTwo[x] = j+1;                         //If position of nonzero elements in arrays A & B
                Result.value[x] = matA[i][j] + matB[i][j];          //are same, then we just add their value
                x++;
            }
            else if(matA[i][j]!=0)
            {
                Result.rowOne[x] = i+1;
                Result.rowTwo[x] = j+1;                      //If only elem of array A is nonzero at that position then
                Result.value[x] = matA[i][j];                    //we assignplace it in separate column
                x++;
            }
            else if(matB[i][j]!=0)
            {
                Result.rowOne[x] = i+1;
                Result.rowTwo[x] = j+1;                      //If only elem of array B is nonzero at that position then
                Result.value[x] = matB[i][j];                    //we assign it in separate column
                x++;
            }
        }
    }

    
    printf("Added RESULT EFFICIENT MATRIX :\n");
    for (int i=0; i<countA+countB-zeroElem-1; i++){
        printf("%d ", Result.rowOne[i] );
    }
    printf("\n");                                           //Printing the elements of Result of type struct effici
    for (int i=0; i<countA+countB-zeroElem-1; i++){             //which indirectly is the final array after summing A & B
        printf("%d ", Result.rowTwo[i] );
    }
    printf("\n");
    for (int i=0; i<countA+countB-zeroElem-1; i++){
        printf("%d ", Result.value[i] );
    }
    
    
    printf("\n\n\n");
    
    return 0;
}