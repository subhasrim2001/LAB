#include<iostream>
using namespace std;
class CIR_QUEUE
{
    int front;
    int rear;
    int size;
    int queue[20];
    public:
    void Insert(int);
    int Delete();
    void Display();
    void Count();
    CIR_QUEUE();
};
void CIR_QUEUE::Count()
{
    if(front<rear)
    {
        cout<<"\nCount="<<rear-front;
    }
    else
    {
        cout<<"\nCount="<<size-front+rear<<endl;
    }
}
void CIR_QUEUE::Display()
{
    CIR_QUEUE Q2;
    int ele;
    do
    {
        ele=Delete();
        if(ele==-1)
        {
            break;
        }
        cout<<ele<<endl;
        Q2.Insert(ele);
    }while(ele!=-1);
    do
    {
        ele=Q2.Delete();
        if(ele==-1)
        {
            break;
        }
        Insert(ele);
    }while(ele!=-1);
}
void CIR_QUEUE::Insert(int x)
{
    if((rear+1)%size==front)
    {
        cout<<"\nFull"<<endl;
        return;
    }
    else
    {
        rear=(rear+1)%size;
        queue[rear]=x;
    }
}
int CIR_QUEUE::Delete()
{
    if(front==rear)
    {
        cout<<"\nQueue Empty\n";
        return -1;
    }
    else
    {
        front=(front+1)%size;
        return queue[front];
    }
}
CIR_QUEUE::CIR_QUEUE()
{
    front=0;
    rear=0;
    size=20;
}
int main()
{
    int ch, x;
    CIR_QUEUE Q1;
    do
    {
        cout<<"\nMENU:\n1.Insert\n2.Delete\n3.Display\n4.Count\n5.Exit\nEnter choice:";
        cin>>ch;
        switch(ch)
        {
            case 1: {
                        cout<<"\nEnter element:";
                        cin>>x;
                        Q1.Insert(x);
                        break;
                    }
            case 2: {
                        x=Q1.Delete();
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
