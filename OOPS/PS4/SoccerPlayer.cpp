#include<iostream>
using namespace std;
class SoccerPlayer
{
    int jersey;
    int goals;
    int assists;
    public:
    friend istream & operator >> (istream &, SoccerPlayer &);
    friend ostream & operator << (ostream &, const SoccerPlayer &);
    bool operator > (SoccerPlayer &);
    SoccerPlayer& operator = (SoccerPlayer &);
};
SoccerPlayer& SoccerPlayer:: operator = (SoccerPlayer &S)
{
    jersey=S.jersey;
    goals=S.goals;
    assists=S.assists;
    return S;
}
bool SoccerPlayer:: operator > (SoccerPlayer &S)
{
    if((goals+assists)>(S.goals+S.assists))
    {
        return true;
    }
    else
    {
        return false;
    }
}
istream & operator >> (istream &in, SoccerPlayer &S)
{
    in>>S.jersey;
    in>>S.goals;
    in>>S.assists;
    return in;
}
ostream & operator << (ostream &out, const SoccerPlayer &S)
{
    out<<"\nJersey:";
    out<<S.jersey;
    out<<"\nGoals:";
    out<<S.goals;
    out<<"\nAssists:";
    out<<S.assists;
    return out;
}
int main()
{
    SoccerPlayer S[11];
    int i;
    for(i=0; i<11; i++)
    {
        cin>>S[i];
    }
    SoccerPlayer Temp=S[0];
    for(i=1; i<11; i++)
    {
        if(S[i]>Temp)
        {
            Temp=S[i];
        }
    }
    cout<<Temp;
    return 0;
}
