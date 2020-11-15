#include<iostream>
using namespace std;
int main()
{
    int n, i, x, count=0, j, f=0;
    cout<<"\nEnter n:";
    cin>>n;
    int *A = new int[n];
    cout<<"\nEnter the numbers:";
    for(i=0; i<n; i++)
    {
        cin>>A[i];
    }
    cout<<"\nEnter x:";
    cin>>x;
    for(i=0; i<n-1; i++)
    {
        f = 0;
        for(j=i+1; j<n; j++)
        {
            if(A[i]==-1 || A[j]==-1)
            {
                continue;
            }
            if(A[i]==A[j])
            {
                f = 1;
                A[j] = -1;
            }
        }
        if(f==0)
        {
            count++;
        }
    }
    if(A[n-1]!=-1)
    {
        count++;
    }
    if(count==x)
    {
        cout<<"\nGood";
    }
    else if(count<x)
    {
        cout<<"\nBad";
    }
    else
    {
        cout<<"\nAverage";
    }
    return 0;
}