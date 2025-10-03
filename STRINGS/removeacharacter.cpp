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
           // remove the character 't' from the original string only 
            s = s.substr(0, i) + s.substr(i + 1);
            i--; // Decrement i to check the next character after erasing
        }
    }
    cout<<s;
    return 0;
}