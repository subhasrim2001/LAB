#include<stdio.h>
void main()
{
    char s[50], ch;
    int i, c=0, j, count=0;
    printf("\nEnter string:");
    scanf("%s", s);
    for(i=0; s[i]!='\0'; i++)
    {
        count=0;
        for(j=0; s[j]!='\0'; j++)
        {
            if(s[i]==s[j])
            {
                count++;
            }
        }
            if(count>c)
            {
                c=count;
                ch=s[i];
            }
    }
    printf("\n%c occured %d times", ch, c);
}
