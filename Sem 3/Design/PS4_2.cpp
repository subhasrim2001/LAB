#include<iostream>
using namespace std;
int F(int X) //divide and conquer
{
    if(X==0)
    {
        return 0;
    }
    else if(X%5 == 0)
    {
        return 1 + F(X/5);
    }
    else
    {
        return 0;
    }
}
int main()
{
    int N, P = 1, sum = 0;
    cout<<"\nEnter N:";
    cin>>N;
    while(sum < N) //do P-1 to do P
    {
        P++;
        sum += F(P);
    }
    cout<<"\nP="<<P;
    return 0;
}
