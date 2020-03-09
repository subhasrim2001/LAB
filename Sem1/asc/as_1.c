/*Numpalindrome*/
#include<stdio.h>
int numpalindrome(int num)
{
    int d, rev, n=num;
    while(n!=0)
    {
        d=n%10;
        rev=(rev*10)+d;
        n=n/10;
    }
    if(num==rev)
    {
        return 1;
    }
    return 0;
}
void main()
{
    int a, b;
    printf("\nEnter number:");
    scanf("%d", &a);
    b=numpalindrome(a);
    if(b)
    {
        printf("\nPalindrome");
    }
    else
    {
        printf("\nNot a palindrome");
    }
}
