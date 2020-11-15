#include<bits/stdc++.h>
using namespace std;
void inorder(int A[], std::vector<int> &v, int n, int i)
{
    if(i < n)
    {
        inorder(A, v, n, 2*i + 1); //left
        v.push_back(A[i]); //root
        inorder(A, v, n, 2*i + 2); //right
    }
}
int minSwaps(std::vector<int> &v, int n)
{
    int i, j, ans = 0, cycle_size = 0;
    std::vector<pair<int, int>> pos(n);
    for(i=0; i<n; i++)
    {
        pos[i].first = v[i];
        pos[i].second = i;
    }
    sort(pos.begin(), pos.end());
    vector<bool> visited(n, false);
    for(i=0; i<n; i++)
    {
        if(visited[i] == 1 || pos[i].second == i)
        {
            continue;
        }
        j = i;
        cycle_size = 0;
        while(!visited[j])
        {
            visited[j] = 1;
            j = pos[j].second;
            cycle_size++;
        }
        if(cycle_size > 0)
        {
            ans += cycle_size - 1; //ex: 1 swap for 2 elements
        }
    }
    return ans;
}
int main()
{
    int n, i, *A;
    std::vector<int> v;
    cout<<"\nEnter number of elements:";
    cin>>n;
    A = new int[n];
    cout<<"\nEnter array representation of complete binary tree:";
    for(i=0; i<n; i++)
    {
        cin>>A[i];
    }
    //1. Obtain inorder traversal
    inorder(A, v, n, 0);
    //2. Find minimum swaps required to sort the array
    cout<<"\nMinimum number of swaps required: "<<minSwaps(v, n);
}