#include<iostream>
using namespace std;
int tripleByValue(int );
void tripleByReference(int &);
int main()
{
    int a, b;
    cout<<"\nEnter a:";
    cin>>a;
    b=tripleByValue(a);
    cout<<"\nValue:\na="<<a<<"\nReturn value="<<b<<"\n";
    tripleByReference(a);
    cout<<"\nReference:\na="<<a;
    return 0;
}
int tripleByValue(int a)
{
    return 3*a;
}
void tripleByReference(int &a)
{
    a=3*a;
}
