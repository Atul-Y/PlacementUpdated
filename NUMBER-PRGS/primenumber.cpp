#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n=37;
    int flag=0;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        flag=1;
        break;
    }
    if(flag==0)
    {
        cout<<"prime number";
    }
    else
    {
        cout<<"not a prime number";
    }
}