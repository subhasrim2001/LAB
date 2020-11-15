#include<iostream>
using namespace std;
int main()
{
    int M, N, i, j, f = 0, f0 = 0;
    cout<<"\nEnter N, M:";
    cin>>N>>M;
    int **A = new int*[N];
    for(i = 0; i < N; i++)
    {
        A[i] = new int[M];
    }
    int *I = new int[N]{}; //to initialise to 0
    cout<<"\nEnter binary representation in M bits:";
    for(i=0; i<N; i++)
    {
        cout<<"\nNo "<<i+1<<":";
        for(j=0; j<M; j++)
        {
            cin>>A[i][j];
        }
    }
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        {
            if(I[j] == f0)
            {
                if(A[j][i] == 1)
                {
                    I[j] = i + 1;
                    f = i + 1;
                }
            }
        }
        f0 = f;
    }
    for(i = 0; i < N; i++)
    {
        if(I[i] == f)
        {
            cout<<"Answer:";
            for(j = 0; j < M; j++)
            {
                cout<<A[i][j]<<" ";
            }
            break;
        }
    }
    delete[] I;
    for(i = 0; i < N; i++)
    {
        delete[] A[i];
    }
    delete[] A;
    return 0;
}
