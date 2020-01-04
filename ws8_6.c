#include<stdio.h>
#include<string.h>
void main()
{
    int i, j, l;
    char s[50], ch;
    printf("\nEnter string:");
    scanf("%s", s);
    l=strlen(s);
    for(i=0, j=l-1; i<l/2; i++, j--)
    {
        ch=s[i];
        s[i]=s[j];
        s[j]=ch;
    }
    printf("\nReversed string:%s", s);
}
