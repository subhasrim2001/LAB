#include<stdio.h>
#include<ctype.h>
void main()
{
    int i;
    char s[50], ch;
    printf("\nEnter string:");
    scanf("%s", s);
    printf("\nVowels:");
    for(i=0; s[i]!='\0'; i++)
    {
        ch=tolower(s[i]);
        switch(ch)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            printf("%c", s[i]);
        }
    }
    printf("\nConsonants:");
    for(i=0; s[i]!='\0'; i++)
    {
        ch=tolower(s[i]);
        switch(ch)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':break;
            default: printf("%c", s[i]);
        }
    }
}
