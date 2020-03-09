#include<stdio.h>
void main()
{
    int i, f=0;
    char ch, s[50];
    printf("\nEnter string:");
    scanf("%s", s);
    printf("\nEnter char:");
    scanf("%*c%c", &ch);
    for(i=0; s[i]!='\0'; i++)
    {
        if(s[i]==ch)
        {
            printf("%c occurred at %d index", ch, i);
            f=1;
        }
    }
    if(!f)
    {
        printf("\nNot found");
    }
}
