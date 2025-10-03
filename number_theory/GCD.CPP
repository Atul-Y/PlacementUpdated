#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    while(b!=0)     //there many other way also to find gcd of a no. so try to see others methods as well for better unnderstanding
    {
        int rem = a%b;
        a=b;
        b=rem;
    }
    return a;
}

int main()
{
    cout<<gcd(24,42);
    return 0;
}