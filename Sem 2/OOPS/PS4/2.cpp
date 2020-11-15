#include<iostream>
using namespace std;
class Set
{
    int count;
    int ele[20];
    public:
    Set();
    void add(int );
    void remove(int );
    void input();
    void display();
    friend Set operator | (Set, Set );
    friend Set operator & (Set, Set);
};
void Set::input()
{
    int i;
    cout<<"\nEnter count:";
    cin>>count;
    cout<<"\nEnter elements:";
    for(i=0; i<count; i++)
    {
        cin>>ele[i];
    }
}
Set operator & (Set S1, Set S2)
{
    Set S;
    int j, k, f=0;
    for(j=0; j<S2.count; j++)
    {
        f=0;
        for(k=0; k<S1.count; k++)
        {
            if(S1.ele[k]==S2.ele[j])
            {
                    f=1;
                    S.add(S2.ele[j]);
                    break;
            }
        }
    }
    S.display();
    return S;
}
Set operator | (Set S1, Set S2)
{
    Set S;
    int i, j, k, f=0;
    for(i=0; i<S1.count; i++)
    {
        S.add(S1.ele[i]);
    }
    for(j=0; j<S2.count; j++)
    {
        f=0;
        for(k=0; k<S1.count; k++)
        {
            if(S1.ele[k]==S2.ele[j])
            {
                    f=1;
                    break;
            }
        }
        if(f==0)
        {
            S.add(S2.ele[j]);
        }
    }
    return S;
}
void Set::display()
{
    int i;
    if(count==0)
    {
        cout<<"\nEmpty set";
        return;
    }
    cout<<"\nThe elements are:";
    for(i=0; i<count; i++)
    {
        cout<<ele[i]<<endl;
    }
}
void Set::remove(int e)
{
    int i, j;
    for(i=0; i<count; i++)
    {
        if(ele[i]==e)
        {
            for(j=i; j<count-1; j++)
            {
                ele[i]=ele[i+1];
            }
            count--;
            break;
        }
    }
}
void Set::add(int e)
{
    int i;
    for(i=0; i<count; i++)
    {
        if(ele[i]==e)
        {
            return;
        }
    }
    ele[count]=e;
    count++;
}
Set::Set()
{
    count=0;
}
int main()
{
    Set S1, S2;
    S1.input();
    S2.input();
    S1.display();
    S2.display();
    S1=S1|S2;
    S1.display();
    S2=S2&S1;
    S2.display();
    return 0;
}
