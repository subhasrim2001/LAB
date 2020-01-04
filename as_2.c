/*Isvowel( char *) that receives a string and counts the number of vowels in a String*/
#include<stdio.h>
#include<ctype.h>
int isvowel(char *p)
{
    char ch;
    int count=0, i;
    for(i=0; p[i]!='\0'; i++)
    {
        ch=*(p+i);
        ch=tolower(ch);
        switch(ch)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':count++;
                     break;
        }
    }
    return count;
}
void main()
{
    int c;
    char s[20];
    printf("\nEnter string:");
    scanf("%s", s);
    c=isvowel(s);
    printf("\nNo of vowel(s):%d\n", c);
}
