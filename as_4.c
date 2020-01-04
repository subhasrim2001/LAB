#include<stdio.h>
int sum(int a)
{
    int val;
    if(a==0)
    {
        return 0;
    }
    val=sum(a-1)+a;
    return val;
}
void main()
{
    int num, ans;
    printf("\nEnter num:");
    scanf("%d", &num);
    ans=sum(num);
    printf("\nSum=%d\n", ans);
}
