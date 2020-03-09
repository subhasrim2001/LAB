#include<stdio.h>
#include<string.h>
#include<math.h>
void main()
{
    int i, val, num=0, l;
    char s[50];
    printf("\nEnter numeric string");
    scanf("%s", s);
    l=strlen(s);
    for(i=0; i<l; i++)
    {
        val=s[i]-48;
        num+=val*pow(10, l-i-1);
    }
    printf("%d", num);
}
