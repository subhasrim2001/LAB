#include<iostream>
using namespace std;
inline void funCircleArea(float );
int main()
{
    float r;
    cout<<"\nEnter radius:";
    cin>>r;
    funCircleArea(r);
    return 0;
}
inline void funCircleArea(float r)
{
    cout<<"Area of circle="<<3.14*r*r<<"\n";
}
