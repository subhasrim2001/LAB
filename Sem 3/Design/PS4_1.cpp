#include<iostream>
using namespace std;
int merges(int A[], int T[], int l, int m, int r)
{
    int i = l, j = m+1, k = l, inv = 0;
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
            inv += m + 1 - i;
        }
        k++;
    }
    if(i>m)
    {
        while(j<=r)
        {
            T[k] = A[j];
            k++;
            j++;
        }
    }
    else
    {
        while(i<=m)
        {
            T[k] = A[i];
            k++;
            i++;
        }
    }
    for(i=l; i<=r; i++)
    {
        A[i] = T[i];
    }
    return inv;
}
int merge_sort(int A[], int T[], int l, int r)
{
    int m, inverse = 0;
    if(l < r)
    {
        m = (l + r)/2;
        inverse+= merge_sort(A, T, l, m);
        inverse+= merge_sort(A, T, m+1, r);
        inverse+= merges(A, T, l, m, r);
    }
    return inverse;
}
int main()
{
    int n, i;
    cout<<"\nEnter n:";
    cin>>n;
    int *A = new int[n];
    int *T = new int[n];
    cout<<"\nEnter numbers:";
    for(i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    cout<<"\nThe number of inversions:"<<merge_sort(A, T, 0, n-1);
    delete[] T;
    delete[] A;
    return 0;
}
