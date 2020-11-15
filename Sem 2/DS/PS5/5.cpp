#include<iostream>
using namespace std;
class QUEUE
{
    int front;
    int rear;
    int size;
    int queue[20];
    public:
    QUEUE();
    void Enqueue(int);
    int Dequeue();
    void Display();
    void Count();
};
void QUEUE::Count()
{
    cout<<"Count="<<rear-front<<endl;
}
void QUEUE::Display()
{
    QUEUE Q2;
    int ele;
    do
    {
        ele=Dequeue();
        if(ele==-1)
        {
            break;
        }
        cout<<ele<<"\n";
        Q2.Enqueue(ele);

    }while(front!=rear);
    do
    {
        ele=Q2.Dequeue();
        if(ele==-1)
        {
            break;
        }
        Enqueue(ele);
    }while(ele!=-1);
}
int QUEUE::Dequeue()
{
    if(rear==front)
    {
        cout<<"\nEmpty";
        return -1;
    }
    else
    {
        front++;
        return queue[front];
    }
}
void QUEUE::Enqueue(int x)
{
    if(rear==size-1)
    {
        cout<<"\nQueue full\n";
        return;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}
QUEUE::QUEUE()
{
    front=rear=-1;
    size=20;
}
int main()
{
    int ch, x;
    QUEUE Q1;
    do
    {
        cout<<"\nMENU:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Count\n5.Exit\nEnter choice:";
        cin>>ch;
        switch(ch)
        {
            case 1: {
                        cout<<"\nEnter element:";
                        cin>>x;
                        Q1.Enqueue(x);
                        break;
                    }
            case 2: {
                        Q1.Dequeue();
                        break;
                    }
            case 3: {
                        Q1.Display();
                        break;
                    }
            case 4: {
                        Q1.Count();
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
