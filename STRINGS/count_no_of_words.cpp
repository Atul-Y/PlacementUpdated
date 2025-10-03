#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s="geeksforgeeks is very good site for coding";
    int c=0;

    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]== ' ')
        {
            c++;
        }

    }
    cout<<c+1;
    return 0;
}