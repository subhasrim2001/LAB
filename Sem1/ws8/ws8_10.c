#include<string.h>
#include<stdio.h>
void main()
{
    int i, l, j;
    char s[50];
    printf("Enter string:");
    scanf("%s", s);
    l=strlen(s);
    for(i=0; i<l; i++)
    {
        for(j=0; j<l-i; j++)
        {
            printf("%c", s[j]);
        }
        printf("\n");
    }
}
