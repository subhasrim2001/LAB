#include<iostream>
using namespace std;
class STACK
{
    int S[20];
    int size;
    int top1;
    int top2;
    public:
    STACK();
    void PUSH(int, int);
    void POP(int);
    void HIGH();
    void LOW();
    void DISP(int );
};
void STACK::DISP(int s)
{
    int t;
    if(s==1)
    {
        t=top1;
        for(; t>=0; t--)
        {
            cout<<S[t]<<"\n";
        }
    }
    else
    {
        t=top2;
        for(; t<size; t++)
        {
            cout<<S[t]<<"\n";
        }
    }
}
void STACK::HIGH()
{
    if((top1+1)>(size-top2))
    {
        cout<<"\nStack 1 has the highest elements\n";
        DISP(1);
    }
    else
    {
        cout<<"\nStack 2 has the highest elements\n";
        DISP(2);
    }
}
void STACK::LOW()
{
    if((top1+1)>(size-top2))
    {
        cout<<"\nStack 2 has the lowest elements\n";
        DISP(2);
    }
    else
    {
        cout<<"\nStack 1 has the lowest elements\n";
        DISP(1);
    }
}
STACK::STACK()
{
    top1=-1;
    top2=size=20;
}
void STACK::PUSH(int x, int s)
{
    if((top2-top1)==1)
    {
        cout<<"\nStack full";
        return;
    }
    else
    {
        if(s==1)
        {
            top1++;
            S[top1]=x;
        }
        else
        {
            top2--;
            S[top2]=x;
        }
    }
}
void STACK::POP(int s)
{
    if(s==1)
    {
        if(top1==-1)
        {
            cout<<"\nStack 1 empty\n";
        }
        else
        {
            top1--;
        }
    }
    else
    {
        if(top2==size)
        {
            cout<<"\nStach 2 empty\n";
        }
        else
        {
            top2++;
        }
    }
}
int main()
{
    int ch, s, x;
    STACK S1;
    do
    {
        cout<<"\nMENU:\n1.PUSH\n2.POP\n3.HIGH\n4.LOW\n5.EXIT\nEnter choice:";
        cin>>ch;
        switch(ch)
        {
            case 1: {
                        cout<<"\nEnter element:";
                        cin>>x;
                        cout<<"\nEnter stack:";
                        cin>>s;
                        S1.PUSH(x, s);
                        break;
                    }
            case 2: {
                        cout<<"\nEnter stack:";
                        cin>>s;
                        S1.POP(s);
                        break;
                    }
            case 3: {
                        S1.HIGH();
                        break;
                    }
            case 4: {
                        S1.LOW();
                        break;
                    }
            case 5: {
                        return 0;
                    }
            default:{
                        cout<<"\nInvalid input\n";
                    }
        }
    }while(ch!=5);
}
