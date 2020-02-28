#include<iostream>
using namespace std;
struct Program
{
    int n_c;
    int n_f;
    int n_l;
    int c;
};
void input(struct Program P[10])
{
    int i;
    for(i=0; i<10; i++)
    {
        cout<<"\nProgram "<<i+1<<":\n";
        cout<<"\nNo of lines of code=:";
        cin>>P[i].n_c;
        cout<<"\nNo of Functions=:";
        cin>>P[i].n_f;
        cout<<"\nNo of Libraries=:";
        cin>>P[i].n_l;
        P[i].c=-1;
    }
}
void disp(struct Program P[10])
{
    int i;
    for(i=0; i<10; i++)
    {
        cout<<"\nProgram "<<i+1<<":\n";
        cout<<"\nNo of lines of code=:";
        cout<<P[i].n_c;
        cout<<"\nNo of Functions=:";
        cout<<P[i].n_f;
        cout<<"\nNo of Libraries=:";
        cout<<P[i].n_l;
        if(P[i].c==0)
        {
            cout<<"\nSoftware File\n";
        }
        else if(P[i].c==1)
        {
            cout<<"\nPackage File\n";
        }

        else if(P[i].c==2)
        {
            cout<<"\nHeader File\n";
        }
    }
}
void check(struct Program P[10])
{
    int i;
    for(i=0; i<10; i++)
    {
        if((P[i].n_l>=10)&&(P[i].n_f>=100)&&(P[i].n_c>=1000000))
        {
            P[i].c=0;
        }
        else if((P[i].n_l>=1)&&(P[i].n_f>=50)&&(P[i].n_c>=1000))
        {
            P[i].c=1;
        }
        else
        {
            P[i].c=2;
        }
    }
}
int main()
{
    struct Program P[10];
    input(P);
    disp(P);
    check(P);
    disp(P);
}
