#include<stdio.h>
void main()
{
    int i, c_u=0, c_l=0, c_s=0;
    char s[50];
    printf("\nEnter string:");
    scanf("%s", s);
    for(i=0; s[i]!='\0'; i++)
    {
        if(isalnum(s[i]))
        {
            if(isalpha(s[i]))
            {
                if(islower(s[i]))
                {
                    c_l++;
                }
                else
                {
                    c_u++;
                }
            }
        }
        else
        {
            c_s++;
        }

    }
    printf("\nUpper=%d\nLower=%d\nSpecial=%d\n", c_u, c_l, c_s);
}
