#include<iostream>
using namespace std;
int pop(char [], int &);
void push(char [], int &, int, int);
void Display_from_top(char [], int);
void Display_from_bottom(char [], int &);
void hasher(char [], int &, int );
int main()
{
    char stack[20];
    int size=20, top=-1;
    hasher(stack, top, size);
    cout<<"\nThe elements in the stack are:";
    Display_from_bottom(stack, top);
}
void hasher(char stack[], int &top, int size)
{
    char ele;
    do
    {
        cout<<"\nEnter char, ^ to terminate, # to pop:";
        cin>>ele;
        if(ele=='^')
        {
            break;
        }
        else if(ele=='#')
        {
            ele=pop(stack, top);
        }
        else
        {
            push(stack, top, size, ele);
        }
    }while(ele!='^');

}
void Display_from_bottom(char stack[], int &top)
{
    char stack2[20], ele;
    int size2=20, top2=-1;
    while(top!=-1)
    {
        ele=pop(stack, top);
        push(stack2, top2, size2, ele);

    }
    Display_from_top(stack2, top2);
    while(top2!=-1)
    {
        ele=pop(stack2, top2);
        push(stack, top, size2, ele);
    }
}
void Display_from_top(char stack[], int top)
{
    int t=top;
    while(t!=-1)
    {
        cout<<stack[t];
        t--;
    }

}
int pop(char stack[], int &top)
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
void push(char stack[], int &top, int size, int num)
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
