#include<stdio.h>
#include<stdlib.h>
int main()
{
    int A[10][10], B[10][10], T1[10][3], T2[10][3], r1, c1, i, j;
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
    printf("\nEnter matrix B:");
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
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
    T2[0][0]=r1;
    T2[0][1]=c1;
    int k2=1;
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
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
    //twins checking
    if(n1!=n2)
    {
        printf("\nNot twins");
        exit(0);
    }
    else
    {
        for(i=1; i<n1+1; i++)
        {
            if((T1[i][0]!=T2[i][0])||(T1[i][1]!=T2[i][1]))
            {
                printf("\nNot twins");
                exit(0);
            }
        }
        printf("\nTwins!!!");
    }
    //addition??
    int T3[10][3];
    T3[0][0]=T1[0][0];
    T3[0][1]=T1[0][1];
    T3[0][2]=T1[0][2];
    for(i=1; i<n1+1; i++)
    {
        T3[i][0]=T1[i][0];
        T3[i][1]=T1[i][1];
        if(T1[i][2]==T2[i][2])
        {
            T3[i][2]=1;
        }
        else if(T1[i][2]>T2[i][2])
        {
            T3[i][2]=2;
        }
        else
        {
            T3[i][2]=-2;
        }
    }
    //triple output
   for(i=0; i<n2+1; i++)
   {
       for(j=0; j<3; j++)
       {
           printf("%d", T3[i][j]);
       }
       printf("\n");
   }
   //the end
    return 0;
}
