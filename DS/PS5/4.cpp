#include<iostream>
using namespace std;
class CAR
{
    int S[20];
    int size;
    int top;
    public:
    CAR();
    void Push(int);
    int GenPop();
    void Pop(int);
    void count();
    int r_top();
};
void CAR::count()
{
    cout<<"\nCount="<<top+1<<endl;
}
int CAR::r_top()
{
    return top;
}
CAR::CAR()
{
    size=20;
    top=-1;
}
void CAR::Push(int car)
{
    if(top==(size-1))
    {
        cout<<"Parking Area full\n";
        return;
    }
    else
    {
        top++;
        S[top]=car;
    }
}
int CAR::GenPop()
{
   if(top==-1)
   {
       return -1;
   }
   else
   {
       top--;
       return S[top+1];
   }
}
void CAR::Pop(int car)
{
    CAR S2;
    int ele;
    do
    {
        ele=GenPop();
        if(ele==car)
        {
            break;
        }
        if(ele==-1)
        {
            break;
        }
        S2.Push(ele);
    }while(top!=-1);
    if(top==-1)
    {
        cout<<"\nCar not found:(\n";
    }
    do
    {
        ele=S2.GenPop();
        Push(ele);
    }while(S2.r_top()!=-1);

}

int main()
{
    int ch, x;
    CAR S1;
    do
    {
        cout<<"\nMENU:\n1.PUSH\n2.POP\n3.COUNT\n4.EXIT\nEnter choice:";
        cin>>ch;
        switch(ch)
        {
            case 1: {
                        cout<<"\nEnter element:";
                        cin>>x;
                        S1.Push(x);
                        break;
                    }
            case 2: {
                        cout<<"\nEnter element:";
                        cin>>x;
                        S1.Pop(x);
                        break;
                    }
            case 3: {
                        S1.count();
                        break;
                    }
            case 4: {
                        return 0;
                    }
            default:{
                        cout<<"\nInvalid input\n";
                    }
        }
    }while(ch!=4);
}
