#include<iostream>
using namespace std;
class MERGE
{
    public:
    int sum(int a, int b)
    {
        return (a+b);
    }
    float sum(float a, float b)
    {
        return (a+b);
    }
    char sum(char a, char b)
    {
        return (a+b);
    }
    void sum(int A[], int B[], int n)
    {
        int i, C[10];
        for(i=0; i<n; i++)
        {
            C[i]=A[i]+B[i];
        }
        cout<<"\nSum array:\n";
        for(i=0; i<n; i++)
        {
            cout<<C[i]<<"\n";
        }
    }
};
int main()
{
    int a, b, A[10], B[10], i, n;
    MERGE M;
    float f1, f2;
    char c1, c2;
    cout<<"\nEnter 2 integers:";
    cin>>a>>b;
    b=M.sum(a, b);
    cout<<"\nSum="<<b<<"\n";
    cout<<"\nEnter 2 decimals:";
    cin>>f1>>f2;
    f1=M.sum(f1, f2);
    cout<<"\nSum="<<f1<<"\n";
    cout<<"\nEnter a char:";
    cin>>c1;
    cout<<"\nEnter another char:";
    cin>>c2;
    c1=M.sum(c1, c2);
    cout<<"\nSum="<<c1<<"\n";
    cout<<"\nEnter size of arrays:";
    cin>>n;
    cout<<"\nEnter array 1:";
    for(i=0; i<n; i++)
    {
        cin>>A[i];
    }
    cout<<"\nEnter array 2:";
    for(i=0; i<n; i++)
    {
        cin>>B[i];
    }
    M.sum(A, B, n);
    return 0;
}
