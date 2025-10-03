#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// int main()
// {
//     string s="yadavatul";
//     reverse(s.begin(),s.end());
//     cout<<s;
//     return 0;
// }
int main()
{
    string s="atul";
    for(int i=0;i<s.length()/2;i++)
    {
        swap(s[i],s[s.length()-i-1]);
    }
    cout<<s;
    return 0;
}