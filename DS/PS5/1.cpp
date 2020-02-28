#include<iostream>
#include<stdlib.h>
using namespace std;
class STACK
{
    int top;
    int stack[20];
    static int size;
    public:
    STACK();
    void count();
    void push(int);
    void Display_from_top();
    int pop();
    void Display_from_bottom();
};
void STACK::count()
{
    cout<<"No of elements:"<<top+1;
}
void STACK::Display_from_top()
{
    int t=top;
    while(t!=-1)
    {
        cout<<stack[t]<<"\n";
        t--;
    }

}
void STACK::Display_from_bottom()
{
    STACK S2;
    int ele;
    int t=top;
    while(top!=-1)
    {
        ele=pop();
        S2.push(ele);
    }
    S2.Display_from_top();
    while(t!=-1)
    {
        ele=S2.pop();
        push(ele);
        t--;
    }
}
int STACK::size=20;
int STACK::pop()
{
    if(top==-1)
    {
        cout<<"\nStack empty";
        return -1;
    }
    else
    {
        top--;
        return stack[top+1];
    }
}
void STACK::push(int num)
{
    if(top==size-1)
    {
        cout<<"\nStack full:";
    }
    else
    {
        top++;
        stack[top]=num;
    }
}
STACK::STACK()
{
    top=-1;
}
int main()
{
    STACK S;
    int ch, val;
    do
    {
        cout<<"\nMENU:\n1.Push\n2.Pop\n3.Exit\n4.Bottom display\n5. Top Display\n6. Count\nEnter choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
                    {
                        cout<<"\nEnter element:";
                        cin>>val;
                        S.push(val);
                        break;
                    }
            case 2:
                    {
                        val=S.pop();
                        cout<<"value="<<val;
                        break;
                    }
            case 3: {
                        exit(0);
                        break;
                    }
            case 4: {
                        S.Display_from_bottom();
                        break;
                    }
            case 5: {
                        S.Display_from_top();
                        break;
                    }
            case 6: {
                        S.count();
                        break;
                    }
            default:{
                        cout<<"\nInvalid Input\n";
                    }

        }
    }while(ch!=3);
}
