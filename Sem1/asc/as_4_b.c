#include<stdio.h>
int sum(int a)
{
    int i, val=0;
    for(i=1; i<=a; i++)
    {
        val+=i;
    }
    return val;
}
void main()
{
    int a, val;
    printf("\nEnter number:");
    scanf("%d", &a);
    val=sum(a);
    printf("\nSum=%d\n", val);
}
