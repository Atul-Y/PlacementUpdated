#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void fabonacci(int a,int b,int n)
{

    if(n==0)
    return;

    int c=a+b;
    cout<<c<<" ";

    a=b;
    b=c;
    fabonacci(a,b,n-1);
}



int main()
{
    int a=0,b=1,c;
    cout<<a<<" "<<b<<" ";
    c=a+b;

    //we will print 7th factorial
    int n=7;
    fabonacci(a,b,n-2);
    return 0;
} 





