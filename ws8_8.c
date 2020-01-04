#include<stdio.h>
void main()
{
    int i;
    char s[50], ch;
    printf("\nEnter string:");
    scanf("%s", s);
    for(i=0; s[i]!='\0'; i++)
    {
        if(isalpha(s[i]))
        {
            ch=tolower(s[i]);
            switch(ch)
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':s[i]='*';
                         break;
                default:s[i]='#';

            }
        }
    }
    printf("\nNew string:%s", s);
}
