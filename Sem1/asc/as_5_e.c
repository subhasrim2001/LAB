#include<stdio.h>
double pow(int n, double d)
{
    double val;
    if(n==0)
    {
        return 1;
    }
    val=d*pow(n-1, d);
    return val;
}
void main()
{
    double x, v;
    int y;
    printf("\nEnter number:");
    scanf("%lf", &x);
    printf("\nEnter power:");
    scanf("%d", &y);
    v=pow(y, x);
    printf("\nValue = %0.2lf", v);
}
