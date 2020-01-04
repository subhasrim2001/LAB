/*GCD*/
int gcd(int a, int b, int c)
{
    int val;
    if((a%c==0)&&(b%c==0))
    {
        return c;
    }
    val=gcd(a, b, c-1);
    return val;
}
void main()
{
    int n1, n2,g;
    printf("\nEnter the nos:");
    scanf("%d%d", &n1, &n2);
    g=gcd(n1, n2, n1);
    printf("\nGCD=%d\n", g);
}
