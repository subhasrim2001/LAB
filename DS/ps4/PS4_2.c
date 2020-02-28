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
    //addition
    int T3[10][3], l=1;
    T3[0][0]=r1;
    T3[0][1]=c1;
    for(i=1, j=1; ; )
    {
        if((i>n1)||(j>n2))
        {
            break;
        }
        else
        {
            if((T1[i][0]==T2[j][0]))
            {
                if((T1[i][1]==T2[j][1]))
                {
                T3[l][0]=T1[i][0];
                T3[l][1]=T1[i][1];
                T3[l][2]=T1[i][2]+T2[j][2];
                i++, j++, l++;
                }
                else if(T1[i][1]>T2[j][1])
                {
                T3[l][0]=T2[j][0];
                T3[l][1]=T2[j][1];
                T3[l][2]=T2[j][2];
                l++, j++;
                }
                else
                {
                T3[l][0]=T1[i][0];
                T3[l][1]=T1[i][1];
                T3[l][2]=T1[i][2];
                i++, l++;
                }

            }
            else if(T1[i][0]>T2[j][0])
            {
                T3[l][0]=T2[j][0];
                T3[l][1]=T2[j][1];
                T3[l][2]=T2[j][2];
                l++, j++;
            }
            else
            {
                T3[l][0]=T1[i][0];
                T3[l][1]=T1[i][1];
                T3[l][2]=T1[i][2];
                i++, l++;
            }
        }
    }
    if(i>n1)
    {
        for(; j<=n2; j++, l++)
        {

            T3[l][0]=T2[j][0];
            T3[l][1]=T2[j][1];
            T3[l][2]=T2[j][2];
        }
    }
    else
    {
        for(; i<=n1; i++, l++)
        {

            T3[l][0]=T1[i][0];
            T3[l][1]=T1[i][1];
            T3[l][2]=T1[i][2];
        }
    }
    T3[0][2]=l-1;
    int n3=l-1;
    //Output T1
   for(i=0; i<n1+1; i++)
   {
       for(j=0; j<3; j++)
       {
           printf("%d", T1[i][j]);
       }
       printf("\n");
   }
   //Output T2
   for(i=0; i<n2+1; i++)
   {
       for(j=0; j<3; j++)
       {
           printf("%d", T2[i][j]);
       }
       printf("\n");
   }
   //Output T3
   for(i=0; i<n3+1; i++)
   {
       for(j=0; j<3; j++)
       {
           printf("%d", T3[i][j]);
       }
       printf("\n");
   }
    return 0;
}
