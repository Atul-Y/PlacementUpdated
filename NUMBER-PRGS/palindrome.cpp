#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n=151;
    int temp=n;
    int rev=0;
    while(n>0)
    {
        int rem =n%10;
        rev=rev*10 + rem;
        n=n/10;
    }
    if(rev==temp)
    {
       cout<<"palindrome" ;
    }
    else
    {
        cout<<"not a palindrome";
    }
}