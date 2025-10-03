#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     string s="ATUL";
//     string p=s;
//     reverse(s.begin(),s.end());
//     if(p==s)
//     {
//         cout<<"palindrome";
//     }
//     else
//     {
//         cout<<"not palindrome";
//     }
//     return 0;
// }

int main()
{
    int flag=0;
    string s="NITQN";
    for(int i=0;i<s.length()/2;i++)
    {
        if(s[i]!=s[s.length()-i-1])
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"palindrome string";
    }
    else
    {
        cout<<"not palindrome string";
    }
}