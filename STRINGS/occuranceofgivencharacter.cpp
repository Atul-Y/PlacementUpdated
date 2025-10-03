#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     string s="geeksforgeeks";
//     char c='e';
//     int count=0;
//     for(int i=0;i<s.length();i++)
//     {
//         if(s[i]==c)
//         {
//             count++;
//         }
//     }
//     cout<<c<<count;
//     return 0;
// }

int main()
{
    string s="geekforgeeks";
    int cnt=count(s.begin(),s.end(),'e');
    cout<<'e'<<" "<<cnt;

}