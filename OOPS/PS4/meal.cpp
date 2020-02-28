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
    cout<<calorie<<M.calorie;
    M2.calorie=calorie+M.calorie;
    cout<<M2.calorie;
    strcpy(M2.name, "Daily Total");
    return M2;
}
ostream & operator << (ostream &out, const Meal &M)
{
    cout<<"\nName:"<<M.name<<"\nCalories"<<M.calorie;
}
istream & operator >> (istream &in, Meal &M)
{
    cin.ignore();
    cout<<"\nEnter name:";
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
    Meal breakfast("Idli", 4), lunch("Dosa", 4), dinner("Pizza", 5), total;
    total= breakfast+lunch+dinner;
    cout<<breakfast;
    cout<<lunch;
    cout<<dinner;
    cout<<total;
    return 0;
}
