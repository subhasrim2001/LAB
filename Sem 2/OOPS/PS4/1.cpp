#include<iostream>
using namespace std;
class Time
{
    int h;
    int m;
    int s;
    public:
    Time(int =0, int =0, int =0);
    void printTime();
    void input();
    Time operator + (Time );
    bool operator < (const Time &);
};
Time Time::operator + (Time T)//overloading #1
{
    Time T2;
    T2.s=(T.s+s)%60;
    T2.m=T.m+m+((T.s+s)/60);
    T2.h=T2.m/60;
    T2.m=T2.m%60;
    T2.h+=T.h+h;
    return T2;
}
void Time::input()//values
{
    cout<<"\nEnter h, m, s:";
    cin>>h>>m>>s;
    cout<<h<<m<<s;
}
bool Time::operator < (const Time &T)
{
    if(h<T.h)
    {
        return true;
    }
    else if(h>T.h)
    {
        return false;
    }
    else if(m<T.m)
    {
        return true;
    }
    else if(m>T.m)
    {
        return false;
    }
    else if(s<T.s)
    {
        return true;
    }
    else
    {
        return false;
    }

}
Time::Time(int h, int m, int s)//constructor
{
    this->h=h;
    this->m=m;
    this->s=s;
}
void Time::printTime()//cur-time
{
    cout<<"\n"<<h<<":"<<m<<":"<<s<<"\n";
}
int main()
{
    Time t1, t2;
    t2.input();
    t2=t1+t2;
    t1.printTime();
    t2.printTime();
    if(t1<t2)
    {
        t1.printTime();
    }
    else
    {
        t2.printTime();
    }
}
