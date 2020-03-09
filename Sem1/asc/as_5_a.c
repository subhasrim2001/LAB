/*factorial of a number   using recursion*/
int fact(int n)
{
    int val;
    if(n==0)
    {
        return 1;
    }
    val=fact(n-1)*n;
    return val;
}
void main()
{
    int num, f;
    printf("\nEnter number:");
    scanf("%d", &num);
    f=fact(num);
    printf("\n%d!=%d\n", num, f);
}
