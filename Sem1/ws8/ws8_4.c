#include<stdio.h>
#include<ctype.h>
void main()
{
    int i;
    char s[50];
    printf("\nEnter string:");
    scanf("%s", s);
    printf("\nUppercase");
    for(i=0; s[i]!='\0'; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\nLowercase");
    for(i=0; s[i]!='\0'; i++)
    {
        printf("%c", tolower(s[i]));
    }
}
