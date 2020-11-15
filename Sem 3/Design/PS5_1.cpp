#include<iostream>
using namespace std;
//Euclidean alg
int GCD(int A, int B)
{
    if(A == 0)
        return B;
    else if(B == 0)
        return A;
    else
    {
        return GCD(B, A%B);
    }

}
int main()
{
    int n, i, j;
    cin>>n;
    for(i = n-2; i>=1; i--)
    {
        if(GCD(n, i) == 1)
        {
            cout<<i;
            break;
        }
    }
    return 0;
}
