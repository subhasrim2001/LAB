#include<iostream>
void merge(int A[], int T[], int l, int m, int r)
{
    int i = l, j = m + 1, k = l;
    while(i<=m && j<=r)
    {
        if(A[i] <= A[j])
        {
            T[k] = A[i];
            i++;
        }
        else
        {
            T[k] = A[j];
            j++;
        }
        k++;
    }
    while(i<=m)
    {
        T[k] = A[i];
        k++;
        i++;
    }
    while(j<=r)
    {
        T[k] = A[j];
        k++;
        j++;
    }
    for(i = l; i <= r; i++)
    {
        A[i] = T[i];
    }
}
void merge_sort(int A[], int T[], int l, int r)
{
    int m;
    if(l < r)
    {
        m = (l + r)/2;
        merge_sort(A, T, l, m);
        merge_sort(A, T, m+1, r);
        merge(A, T, l, m, r);
    }
}
using namespace std;
int main()
{
    int n, k, i, sum = 0;
    cout<<"\nEnter n:";
    cin>>n;
    int *A = new int[n];
    int *T = new int[n];
    cout<<"\nEnter the sequence:";
    for(i=0; i<n; i++)
    {
        cin>>A[i];
    }
    cout<<"\nEnter k:";
    cin>>k;
    if(k >= n)
    {
        cout<<"\nNot possible, sum = 0";
        return 0;
    }
    //Do sorting and find k+1 element from behind.
    merge_sort(A, T, 0, n-1);
    i = n - 1 - k;
    for(; i>=0; i--)
    {
        sum += A[i];
    }
    cout<<"\nSum of special numbers:"<<sum;
    delete[] A;
    delete[] T;
    return 0;
}
