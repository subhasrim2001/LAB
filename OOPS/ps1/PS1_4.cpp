#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
struct Element
{
    int n;
    char name[20];
    char symbol[4];
    char clas[20];
    int w;
    int e[7];
};
void input(struct Element *);
void list(struct Element *);
int main()
{
    struct Element E[10];
    input(E);
    list(E);
    getch();
}
void input(struct Element *E)
{
    int i, j;
    for(i=0; i<10; i++)
    {
        cout<<"\nElement "<<i+1<<":\n";
        cout<<"\nAtomic no:";
        cin>>E[i].n;
        cout<<"\nName:";
        cin>>E[i].name;
        cout<<"\nClass:";
        cin>>E[i].clas;
        cout<<"\nSymbol:";
        cin>>(E[i].symbol);
        cout<<"\nAtomic Weight:";
        cin>>E[i].w;
        cout<<"\nNo of electrons:";
        {
            for(j=0; j<7; j++)
            {
                cout<<"\nShell "<<j
                +1<<":";
                cin>>E[i].e[j];
            }
        }
    }
}
void list(struct Element *E)
{
    int i, f=0;;
    for(i=0; i<10; i++)
    {
        if(E[i].n>11)
        {
            cout<<"\nElement name:"<<E[i].name;
            f=1;
        }
    }
    if(f==0)
    {
        cout<<"\nNo element found";
        return;
    }
}
