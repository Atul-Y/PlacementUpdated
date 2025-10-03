#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void divisible(int n,int a,int b)
{
    int c1=n/a;
    int c2=n/b;
    int c3=n/(a*b);
    int ans=c1+c2-c3;
    cout<<ans;
}

int main ()
{
    divisible(40,5,7);
    return 0;
}