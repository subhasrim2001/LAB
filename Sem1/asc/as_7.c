#include<stdio.h>
void main()
{
    char products[4][20]={"MP3 Player", "WII", "DVD Player", "Digital Camera"};
    double prices[4]={5000, 10000, 2000, 8000}, total=0;
    int i, sale[4], tot=0, m, l;
    for(i=0; i<4; i++)
    {
        printf("\nThe no of %s sold:", products[i]);
        scanf("%d", sale+i);
    }
    printf("\nThe statistics of sales\n");
    printf("\nProduct Unit\tPrice\t\tQTY\tTotal Price\n");
    for(i=0; i<4; i++)
    {
        total+=prices[i]*sale[i];
        if(i==1)
        {
            printf("%s\t\t%lf\t%d\t%lf\n", products[i], prices[i], sale[i], prices[i]*sale[i]);
        }
        else
        {
            printf("%s\t%lf\t%d\t%lf\n", products[i], prices[i], sale[i], prices[i]*sale[i]);
        }
        tot+=sale[i];
    }
    printf("total\t\t\t\t%d\t%lf\n", tot, total);
    /*Most and least*/
    m=0;
    l=0;
    for(i=1; i<4; i++)
    {
        if(sale[m]<sale[i])
        {
            m=i;
        }
        else if(sale[i]<sale[l])
        {
            l=i;
        }
    }
    printf("\nLeast sold=%s-%d\nMost sold=%s-%d\n", products[l], sale[l], products[m], sale[m]);
}
