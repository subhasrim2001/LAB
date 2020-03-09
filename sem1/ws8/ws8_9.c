#include<stdio.h>
void main()
{
    int i, j;
    char s[50];
    printf("\nEnter string:");
    scanf("%s", s);
    for(i=0; s[i]!='\0'; i++)
    {
        for(j=0; j<=i; j++)
        {
            printf("%c", s[j]);
        }
        printf("\n");
    }
}
