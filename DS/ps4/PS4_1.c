#include<stdio.h>
int main()
{
    int A[10][10], r, c, T[10][3], i, j;
    printf("\nEnter no of rows and columns:");
    scanf("%d%d", &r, &c);
    printf("\nEnter matrix:");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            scanf("%d", &(A[i][j]));
        }
    }
    //triple
    T[0][0]=r;
    T[0][1]=c;
    int k=1;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(A[i][j]!=0)
            {
                T[k][0]=i;
                T[k][1]=j;
                T[k][2]=A[i][j];
                k++;
            }
        }
    }
    T[0][2]=k-1;
    //Transpose of A
    int A_t[10][10];
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            A_t[j][i]=A[i][j];
        }
    }
    //Transpose of T
    //k=no of rows(non zero+1)
    //n=no of non zero
    int T_t[10][3], n=k-1, l=1;
    for(i=1; i<c; i++)
    {
        for(j=1; j<n+1; j++)
        {
            if(T[j][1]==i)
            {
                T_t[l][0]=T[j][1];
                T_t[l][1]=T[j][0];
                T_t[l][2]=T[j][2];
                l++;
            }
        }
    }
    T_t[0][0]=c;
    T_t[0][1]=r;
    T_t[0][2]=l-1;
   //End
   //O/P
   //1. Matrix
   for(i=0; i<r; i++)
   {
       for(j=0; j<c; j++)
       {
           printf("%d", A[i][j]);
       }
       printf("\n");
   }
   //2. Triple
   for(i=0; i<n+1; i++)
   {
       for(j=0; j<3; j++)
       {
           printf("%d", T[i][j]);
       }
       printf("\n");
   }
   //3. Transpose of A
   for(i=0; i<c; i++)
   {
       for(j=0; j<r; j++)
       {
           printf("%d ", A_t[i][j]);
       }
       printf("\n");
   }
   //4.
   int n2=T_t[0][2];
   for(i=0; i<n2+1; i++)
   {
       for(j=0; j<3; j++)
       {
           printf("%d", T_t[i][j]);
       }
       printf("\n");
   }

}
