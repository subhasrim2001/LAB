#include<stdio.h>
int func(int x)
{
    int val;
    if(x==0)
    {
        return 1;
    }
    val=(func(x-1)*x) + x;
    return val;
}
void main()
{
    int num, v;
    printf("\nEnter x:");
    scanf("%d", &num);
    v=func(num);
    printf("\nValue of function=%d\n", v);
}
