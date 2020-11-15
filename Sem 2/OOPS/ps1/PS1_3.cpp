#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
struct Dictionary
{
    char term[10];
    char meaning[30];
};
void search(struct Dictionary *, char *);
void read(struct Dictionary *);
void start(struct Dictionary *);
int main()
{
    char key[20];
    struct Dictionary D[5];
    read(D);
    cout<<"\nEnter term:";
    gets(key);
    search(D, key);
    start(D);
}
void search(struct Dictionary *p, char *a)
{
    int i;
    for(i=0; i<5; i++)
    {
        if(strcmp(p[i].term, a)==0)
        cout<<"\n"<<p[i].meaning<<"\n";
        return;
    }
        printf("\nMeaning not found!");
}
void read(struct Dictionary *p)
{
    int i;
    for(i=0; i<5; i++)
    {
        cout<<"\nWord "<<i+1<<":";
        cout<<"\nEnter term:";
        gets(p[i].term);
        cout<<"\nEnter meaning:";
        gets(p[i].meaning);
    }
}
void start(struct Dictionary *p)
{
    int count=0, i;
    for(i=0; i<5; i++)
    {
        if(p[i].term[0]=='a'||p[i].term[0]=='A')
        {
            cout<<p[i].term<<"\n";
            count++;
        }
    }
    if(count==0)
    {
        cout<<"\nNo term exists";
        return;
    }
    cout<<"\nNo of words="<<count;
}
