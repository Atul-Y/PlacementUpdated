#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num=13;
    int i=1,rem=0,bin=0;
    while(num!=0)
    {
        rem=num%2;
        bin=bin+rem*i;
        i=i*10;
        num=num/2;  
    }
    cout<<bin;
    return 0;
}