#include<iostream>
using namespace std;
struct Set
{
    int size;
    int *ptr;
};
void input(struct Set &A)
{
    int i;
    cout<<"\nEnter size:";
    cin>>A.size;
    int *p=new int[A.size];
    A.ptr=p;
    cout<<"\nEnter elements:";
    for(i=0; i<A.size; i++)
    {
        cin>>A.ptr[i];
    }
}
void disp(struct Set A)
{
    int i;
    cout<<"\nSize="<<A.size<<"\nElements:";
    for(i=0; i<A.size; i++)
    {
        cout<<"\n"<<A.ptr[i];
    }
}
struct Set merge(struct Set S1, struct Set S2)
{
    int i, j, k, f=0;
    for(i=S1.size, j=0; j<S2.size; j++)
    {
        f=0;
        for(k=0; k<S1.size; k++)
        {
            if(S1.ptr[k]==S2.ptr[j])
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            S1.ptr[i]=S2.ptr[j];
            i++;
        }
    }
    S1.size=i;
    return S1;
}
int main()
{
    struct Set S1, S2, S3;
    cout<<"\nSet 1:\n";
    input(S1);
    disp(S1);
    cout<<"\nSet 2:\n";
    input(S2);
    disp(S2);
    S3=merge(S1, S2);
    disp(S3);
}
