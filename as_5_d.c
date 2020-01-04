/*Reverse ‘n’ characters.*/
#include<stdio.h>
void rev(char p[20], int a, int b)
{
    char t;
    if(a>=b)
    {
        return;
    }
    t=p[a];
    p[a]=p[b];
    p[b]=t;
    rev(p, a+1, b-1);
    return;
}
void main()
{
    int n;
    char A[20];
    printf("\nEnter string:");
    scanf("%s", A);
    printf("\nEnter no of char:");
    scanf("%d", &n);
    rev(A, 0, n-1);
    printf("\nNew string:%s\n", A);
}
