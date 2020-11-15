#include<bits/stdc++.h>
using namespace std;
int find_pos(string s, char c)
{
    int i;
    for(i = 0; i < s.length(); i++)
    {
        if(s[i] == c)
        {
            return i;
        }
    }
    //note: not considering case of not found because pattern string will have the element
}
int main()
{
    string pattern, input, output;
    int i, ni, temp, val;
    cout<<"\nEnter pattern:";
    cin>>pattern;
    cout<<"\nEnter input:";
    cin>>input;
    //make distance, char pair
    vector< pair<int, char> > D;
    ni = input.length();
    temp = find_pos(pattern, input[0]);
    for(i = 0; i < ni; i++)
    {
        val = find_pos(pattern, input[i]) - temp;
        D.push_back(make_pair(val, input[i]));
    }
    sort(D.begin(), D.end());
    output = "";
    for(i=0; i<ni; i++)
    {
        output+=D[i].second;
    }
    cout<<"\nThe sorted string is:"<<output<<"\n";
}
