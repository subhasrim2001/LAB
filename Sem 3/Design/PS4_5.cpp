#include<iostream>
#include<cmath>
using namespace std;
int min_value(int a, int b)
{
    if(a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void min_gap(int A[], int n, int &c1, int &c2)
{
    int i, temp, m_gap = abs(A[0] - A[1]), mm_gap = abs(A[1] - A[2]);
    c1 = 0;
    c2 = 1;
    for(i=1; i<n-1; i++)
    {
        if((A[i+1] - A[i]) < m_gap)
        {
            m_gap = A[i+1] - A[i];
            if(i + 2 < n)
            {
                 mm_gap = min_value(A[i+2] - A[i+1], A[i] - A[i-1]);
            }
            else
            {
                mm_gap = A[i] - A[i-1];
            }
            c1 = i;
            c2 = i+1;
        }
        else if(A[i+1] - A[i] == m_gap)
        {
            if(i + 2 < n)
            {
                 temp = min_value(A[i+2] - A[i+1], A[i] - A[i-1]);
            }
            else
            {
                temp = A[i] - A[i-1];
            }
            if(temp < mm_gap)
            {
                c1 = i;
                c2 = i+1;
                mm_gap = temp;
            }
        }
    }
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
int main()
{
    int Test, i, N, M, j, c1, c2, k;
    cout<<"\nEnter no. of test cases:";
    cin>>Test;
    for(k = 0; k < Test; k++)
    {
        cout<<"\nEnter N, M:";
        cin>>N>>M;
        if(N<=2)
        {
            cout<<"\nNot possible to arrange\n";
            continue;
        }
        int A[50];
        int T[50];
        cout<<"\nEnter color nos:";
        for(j = 0; j < N; j++)
        {
            cin>>A[j];
        }
        merge_sort(A, T, 0, N-1); //divide and conquer

        //find the min gap between points in the x axis - between color nos
        min_gap(A, N, c1, c2);
        //Note: Gap in y axis is fixed
        //Final part: comp
        /*
            Divide into cases
            1. left  and right
            2. Sides
        */
        long double p = 0;// for top and bottom
        for(i=0; i<N-1; i++)
        {
            p += A[i+1] - A[i];
            if(A[i+1]==c1)
            {
                p+= sqrt(pow((A[i+1] - A[i]), 2) + pow((c1 - A[i]), 2));

            }
            else if(A[i] == c1)
            {
                if(i-1 >= 0)
                    p+= sqrt(pow((A[i+1] - A[i]), 2) + pow((c1 - A[i-1]), 2));
                else
                    p+= sqrt(pow((A[i+1] - A[i]), 2) + pow((c1 - A[i+2]), 2));
            }
            else if(A[i] == c2)
            {
                p+= sqrt(pow((A[i+1] - A[i]), 2) + pow((c1 - A[i]), 2));
            }
            else
            {
                p+=A[i+1] - A[i];
            }
        }
        p+= c2 - c1;
        if(c1 == A[0])
        {
            p+= A[2] - c2;
        }
        else if(c2 == A[N-1])
        {
            p+= c1 - A[N-3];
        }
        else
        {
            p+= c2 - c1;
        }
        //perimeter found
        cout<<"\nCost = "<<p * M<<"\n";
    }
}
