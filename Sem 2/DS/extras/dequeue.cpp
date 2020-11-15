#include<iostream>
using namespace std;
class deque
{
    int front1;
    int rear1;
    int front2;
    int rear2;
    static int size;
    int deq[20];
    public:
    deque();
    void ins(int, int);
    int del(int);
};
int deque::del(int ch)
{
    if(ch==1)
    {
        if(rear1==front1)
        {
            return -1;
        }
        else
        {
            front1++;
            return deque[front1];
        }
    }
    else
    {
        if(rear2==front2)
        {
            return -1;
        }
        else
        {
            front2--;
            return deque[front2]
        }
    }
}
void deque::ins(int ele, int ch)
{
    if(rear2+1==rear1)
    {
        cout<<"Deque Full\n";
    }
    else
    {
        if(ch==1)
        {
            rear1++;
            dequeue[rear1]=ele;
        }
        else
        {
            rear2--;
            dequeue[rear2]=ele;
        }
    }
}
