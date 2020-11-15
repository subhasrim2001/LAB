#include<stdio.h>
int main()
{
    int A[10][10], r1, c1, B[10][10], r2, c2, i, j, T1[10][3], T2[10][3];
    printf("\nEnter no of rows and columns of A:");
    scanf("%d%d", &r1, &c1);
    printf("\nEnter matrix A:");
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
        {
            scanf("%d", &(A[i][j]));
        }
    }
    printf("\nEnter no of rows and columns of B:");
    scanf("%d%d", &r2, &c2);
    printf("\nEnter matrix B:");
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
        {
            scanf("%d", &(B[i][j]));
        }
    }
    //triple 1
    T1[0][0]=r1;
    T1[0][1]=c1;
    int k1=1;
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
        {
            if(A[i][j]!=0)
            {
                T1[k1][0]=i;
                T1[k1][1]=j;
                T1[k1][2]=A[i][j];
                k1++;
            }
        }
    }
    T1[0][2]=k1-1;
    int n1=k1-1;
    //triple 2
    T2[0][0]=r2;
    T2[0][1]=c2;
    int k2=1;
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
        {
            if(B[i][j]!=0)
            {
                T2[k2][0]=i;
                T2[k2][1]=j;
                T2[k2][2]=B[i][j];
                k2++;
            }
        }
    }
    T2[0][2]=k2-1;
    int n2=k2-1;

    //Transpose of T2
    //k2=no of rows(non zero+1)
    //n2=no of non zero
    int T2_t[10][3], l=1;
    for(i=0; i<c2; i++)
    {
        for(j=1; j<n2+1; j++)
        {
            if(T2[j][1]==i)
            {
                T2_t[l][0]=T2[j][1];
                T2_t[l][1]=T2[j][0];
                T2_t[l][2]=T2[j][2];
                l++;
            }
        }
    }
    T2_t[0][0]=c2;
    T2_t[0][1]=r2;
    T2_t[0][2]=l-1;
   //End
//-------------------------------------------------------//ok till this
   //Most Important
   //Multiplication
   //Normal Matrix
    int C_t[10][3]={0};
    int C[10][10]={0}, n3, k=1;
    for(i=1; i<n1+1; i++)
    {
        for(j=1; j<n2+1; j++)
        {
            if(T1[i][1]==T2_t[j][1])
            {
                C[(T1[i][0])][(T2_t[j][0])]+=T1[i][2]*T2_t[i][2];
            }
        }
    }
    for(i=0; i<r1; i++)
    {
       for(j=0; j<c2; j++)
       {
           printf("%d", C[i][j]);
       }
       printf("\n");
    }
    //Triple Conversion
    //triple 3
    C_t[0][0]=r1;
    C_t[0][1]=c2;
    int k4=1;
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c2; j++)
        {
            if(C[i][j]!=0)
            {
                C_t[k4][0]=i;
                C_t[k4][1]=j;
                C_t[k4][2]=C[i][j];
                k4++;
            }
        }
    }
    C_t[0][2]=k4-1;
    int n4=k4-1;

    //Display Triple
   for(i=0; i<n4+1; i++)
   {
       for(j=0; j<3; j++)
       {
           printf("%d", C_t[i][j]);
       }
       printf("\n");
   }
    return 0;
}
