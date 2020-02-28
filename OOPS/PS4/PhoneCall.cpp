#include<iostream>
using namespace std;
class PhoneCall {
    long number;
    int length;
    float rate;
    public:
    friend istream & operator >> (istream &, PhoneCall &);
    friend ostream & operator << (ostream &, const PhoneCall &);
    bool operator == (const PhoneCall &);
};
bool PhoneCall::operator == (const PhoneCall &P)
{
    if(number==P.number)
    {
        return true;
    }
    return false;
}
istream & operator >> (istream &in, PhoneCall &P)
{
    in>>P.number;
    in>>P.length;
    in>>P.rate;
}
ostream & operator << (ostream &out, const PhoneCall &P)
{
    out<<"\nNumber:";
    out<<P.number;
    out<<"\nLength:";
    out<<P.length;
    out<<"\nRate:";
    out<<P.rate;
}
int main()
{
    PhoneCall P[10];
    int i, j;
    for(i=0; i<10; i++)
    {
        cin>>P[i];
        for(j=0; j<i; j++)
        {
            if(P[i]==P[j])
            {
                cout<<"\nCannot place phone call to this number\nEnter again:";
                i--;
                break;
            }
        }
    }
    return 0;
}
