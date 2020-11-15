//Merge sort and find > X using binary search
#include<iostream>
int binary_search(int A[], int n, int k)
{
    int l = 0, r = n - 1, m;
    while(l <= r)
    {
        m = (l + r)/2;
        if(k == A[m])
        {
           return binary_search(A, n, k+1);
        }
        else if(k < A[m])
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return k;
}
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
    int n, i, x;
    cout<<"\nEnter n:";
    cin>>n;
    int *A = new int[n];
    int *T = new int[n];
    cout<<"\nEnter the array:";
    for(i=0; i<n; i++)
    {
        cin>>A[i];
    }
    cout<<"\nEnter X:";
    cin>>x;
    merge_sort(A, T, 0, n-1);
    int ans = binary_search(A, n, x+1);
    cout<<ans;
    delete[] A;
    delete[] T;
    return 0;
}
