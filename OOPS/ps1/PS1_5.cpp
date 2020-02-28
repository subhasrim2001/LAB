#include<iostream>
#include<string.h>
using namespace std;
struct Vehicle
{
    int rno;
    char m_n[20];
    int y;
    char model[20];
    int type;
    char color[20];
};
void input(struct Vehicle []);
void d_year(struct Vehicle [], int);
void d_m_no(struct Vehicle [], char []);
void disp(struct Vehicle [], int );
void r_disp(struct Vehicle [], int );
int main()
{
    int no;
    char M_name[20];
    struct Vehicle V[3];
    input(V);
    cout<<"\nEnter year:";
    cin>>no;
    d_year(V, no);
    cout<<"\nEnter manufacturer's name:";
    cin>>M_name;
    d_m_no(V, M_name);
    cout<<"\nEnter registration number:";
    cin>>no;
    r_disp(V, no);
    return 0;
}
void input(struct Vehicle V[3])
{
    int i;
    for(i=0; i<3; i++)
    {
        cout<<"\nEnter vehicle "<<i+1<<":\n";
        cout<<"\nEnter registration no:";
        cin>>V[i].rno;
        cout<<"\nEnter manufacurer's name:";
        cin>>V[i].m_n;
        cout<<"\nEnter manufacurer year:";
        cin>>V[i].y;
        cout<<"\nEnter model:";
        cin>>V[i].model;
        cout<<"\nEnter type of vehicle(2/4):";
        cin>>V[i].type;
        cout<<"\nEnter colour:";
        cin>>V[i].color;
    }
}
void d_year(struct Vehicle V[3], int year)
{
    int f=0, i;
    for(i=0; i<3; i++)
    {
        if(V[i].y==year)
        {
            disp(V, i);
            f=1;
        }
    }
    if(f==0)
    {
        cout<<"\nNo vehicle found";
    }
}
void d_m_no(struct Vehicle V[3], char name[20])
{
    int i, f=0;
    for(i=0; i<3; i++)
    {
        if(strcmp(V[i].m_n, name)==0)
        {
            disp(V, i);
            f=1;
        }
    }
    if(f==0)
    {
        cout<<"\nNo vehicle found";
    }
}
void disp(struct Vehicle V[3], int i)
{
        cout<<"\nVehicle "<<i+1<<":\n";
        cout<<"\nRegistration no:";
        cout<<V[i].rno;
        cout<<"\nManufacurer's name:";
        cout<<V[i].m_n;
        cout<<"\nManufacurer year:";
        cout<<V[i].y;
        cout<<"\nEnter model:";
        cout<<V[i].model;
        cout<<"\nEnter type of vehicle(2/4):";
        cout<<V[i].type;
        cout<<"\nEnter colour:";
        cout<<V[i].color;
}
void r_disp(struct Vehicle V[3], int r)
{
        int f=0, i;
    for(i=0; i<3; i++)
    {
        if(V[i].rno==r)
        {
            disp(V, i);
            f=1;
        }
    }
    if(f==0)
    {
        cout<<"\nNo vehicle found";
    }
}
