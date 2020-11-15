//Q5
#include<iostream>
using namespace std;
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
int findIndex(int A[], int n, int i, int M) //using binary search
{
    int j;
    for(j=0; j<n; j++)
    {
        if(A[j] >= (M+A[i]))
        {
            return j;
        }
    }
}
int main()
{
    int N, M, i, count=0;
    cout<<"\nEnter N:";
    cin>>N;
    int *A = new int[N];
    int *T = new int[N];
    cout<<"\nEnter the elements:";
    for(i=0; i<N; i++)
    {
        cin>>A[i];
    }
    cout<<"\nEnter M:";
    cin>>M;
    //Find sum upto value
    for(i=1; i<N; i++)
    {
        A[i]+=A[i-1];
        if(A[i] > M)
        {
           count++;
        }
    }
    if(A[0] > M)
        count++;
    //Counted no of elements where sum > M
    //Sort array
    merge_sort(A, T, 0, N-1);
    //find for each ele
    for(i = 0; i < N; i++)
    {
        count+= N - findIndex(A, N, i, M);
	/* use upper_bound() to make time complexity O(nlogn) */
    }
    cout<<"\nNo of subarrays:"<<count;
    delete[] A;
    delete[] T;
    return 0;
}


