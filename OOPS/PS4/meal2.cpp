#include<iostream>
#include<cstring>
using namespace std;
class Meal
{
    char name[20];
    int calorie;
    public:
    Meal(char * ="Food", int =0);
    friend istream & operator >> (istream &, Meal &);
    friend ostream & operator << (ostream &, const Meal &);
    Meal operator + (Meal M);
};
Meal Meal::operator + (Meal M)
{
    Meal M2;
    M2.calorie=calorie+M.calorie;
    strcpy(M2.name, "Daily Total");
    return M2;
}
ostream & operator << (ostream &out, const Meal &M)
{
    cout<<"\nName:"<<M.name<<"\nCalories"<<M.calorie;
}
istream & operator >> (istream &in, Meal &M)
{
    cout<<"\nEnter name:";
    cin.ignore();
    cin.getline(M.name, 20);
    cout<<"\nEnter calories:";
    cin>>M.calorie;
}
Meal::Meal(char *n, int cal)
{
    strcpy(name, n);
    calorie=cal;
}
int main()
{
    Meal M[21], total("Daily Total", 0);
    int i;
    for(i=0; i<21; i++)
    {
        cin>>M[i];
        total=total+M[i];
    }
    cout<<total;
    return 0;
}
