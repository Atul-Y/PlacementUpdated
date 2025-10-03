#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s="gttksforgttks";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='t')
        {
            s[i]='e';
        }
    }
    cout<<s;
    return 0;
}