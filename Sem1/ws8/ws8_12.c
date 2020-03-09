#include<stdio.h>
void main()
{
    char s1[20], s2[20], s3[50], ch;
    int i, count, c, j, f=0;
    printf("\nEnter string 1:");
    scanf("%s", s1);
    printf("\nEnter string 2:");
    scanf("%s", s2);
    printf("\nEnter string 3:");
    scanf("%s", s3);
    for(i=0; s3[i]!='\0'; i++)
    {
        ch=s3[i];
        count=0;
        for(j=0; s3[j]!='\0'; j++)
        {
            if(ch==s3[j])
            {
                count++;
            }
        }
        c=0;
        for(j=0; s1[j]!='\0'; j++)
        {
            if(ch==s1[j])
            {
                c++;
            }
        }
        for(j=0; s2[j]!='\0'; j++)
        {
            if(ch==s2[j])
            {
                c++;
            }
        }
        if(c!=count)
        {
            f=1;
            printf("\nNo");
            break;
        }
    }
    if(!f)
    {
        printf("\nYes");
    }
}
