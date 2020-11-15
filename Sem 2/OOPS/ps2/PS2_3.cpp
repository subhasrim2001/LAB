#include<iostream>
using namespace std;
int fibonacci(int );
float fibonacci(float );
long fibonacci(long );
int main()
{
    int a;
    float b;
    long c;
    cout<<"\nEnter int:";
    cin>>a;
    cout<<fibonacci(a);
    cout<<"\nEnter float:";
    cin>>b;
    cout<<fibonacci(b);
    cout<<"\nEnter long:";
    cin>>c;
    cout<<fibonacci(c);
    return 0;
}
int fibonacci(int a)
{
    if(a==1||a==0)
    {
        return a;
    }
    else
    {
        return (fibonacci(a-1)+fibonacci(a-2));
    }
}
float fibonacci(float a)
{
    if(a==1||a==0)
    {
        return a;
    }
    else
    {
        return (fibonacci(a-1)+fibonacci(a-2));
    }
}
long fibonacci(long a)
{
    if(a==1||a==0)
    {
        return a;
    }
    else
    {
        return (fibonacci(a-1)+fibonacci(a-2));
    }
}
