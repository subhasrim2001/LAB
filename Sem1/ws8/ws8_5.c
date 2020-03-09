#include<stdio.h>
void main()
{
    int i;
    char s[50];
    printf("\n/Enter string:");
    scanf("%s", s);
    for(i=0; s[i]!='\0'; i++)
    {
        if(isupper(s[i]))
        {
            printf("%c", tolower(s[i]));
        }
        else
        {
            printf("%c", toupper(s[i]));
        }
    }

}
