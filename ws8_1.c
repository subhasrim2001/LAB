#include<stdio.h>
void main()
{
    char s[50];
    int i;
    printf("\nEnter string:");
    scanf("%s", s);
    for(i=0; s[i]!='\0'; i++)
    {
        printf("%c", s[i]);
    }
}
