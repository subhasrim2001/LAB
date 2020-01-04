/*To generate Fibonacci sequence  */
void fibo(int a, int b, int n)
{
    static int count=2;
    if(count==n)
    {
            return;
    }
    int c;
    c=a+b;
    printf("%d\t", c);
    count++;
    fibo(b, c, n);
    return;
}
void main()
{
    int no;
    printf("\nEnter no of terms of fibonacci sequence:");
    scanf("%d", &no);
    printf("\n0\t1\t");
    fibo(0, 1, no);
}
