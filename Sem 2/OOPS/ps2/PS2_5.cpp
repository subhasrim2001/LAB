#include<iostream>
using namespace std;
class Maximum
{
    public:
    int big(int a, int b)
    {
        if(a>b)
        {
            return a;
        }
        return b;
    }
    int big(int a, int b, int c)
    {
        if((a>=b)&&(a>=c))
        {
            return a;
        }
        else if(b>c)
        {
            return b;
        }
        return c;
    }
    float big(float a, float b)
    {
        if(a>b)
        {
            return a;
        }
        return b;
    }
    float big(float a, float b, float c)
    {
        if((a>=b)&&(a>=c))
        {
            return a;
        }
        else if(b>c)
        {
            return b;
        }
        return c;
    }
    char big(char a, char b)
    {
        if(a>b)
        {
            return a;
        }
        return b;
    }
    char big(char a, char b, char c)
    {
        if((a>=b)&&(a>=c))
        {
            return a;
        }
        else if(b>c)
        {
            return b;
        }
        return c;
    }
    long big(long a, long b)
    {
        if(a>b)
        {
            return a;
        }
        return b;
    }
    long big(long a, long b, long c)
    {
        if((a>=b)&&(a>=c))
        {
            return a;
        }
        else if(b>c)
        {
            return b;
        }
        return c;
    }
};
int main()
{
    int a, b, c;
    char d, e, f;
    float g, h, i;
    long j, k, l;
    Maximum M;
    cout<<"\nEnter 3 integers:";
    cin>>a>>b>>c;
    c=M.big(a, b, c);
    b=M.big(a, b);
    cout<<"\nThe greatest of the 3 is "<<c<<"\nThe greatest of 1 and 2 is "<<b<<"\n";
    cout<<"\nEnter 3 characters:";
    cin>>d>>e>>f;
    f=M.big(d, e, f);
    e=M.big(d, e);
    cout<<"\nThe greatest of the 3 is "<<f<<"\nThe greatest of 1 and 2 is "<<e<<"\n";
    cout<<"\nEnter 3 decimals:";
    cin>>g>>h>>i;
    i=M.big(g, h, i);
    h=M.big(g, h);
    cout<<"\nThe greatest of the 3 is "<<i<<"\nThe greatest of 1 and 2 is "<<h<<"\n";
    cout<<"\nEnter 3 long:";
    cin>>j>>k>>l;
    l=M.big(j, k, l);
    k=M.big(j, k);
    cout<<"\nThe greatest of the 3 is "<<l<<"\nThe greatest of 1 and 2 is "<<k<<"\n";
    return 0;
}
