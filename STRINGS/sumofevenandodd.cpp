#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string sum="";
    string odd="";
    string s="ABCDE";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]%2==0){
            sum=sum+s[i];
        }
        else{
            odd=odd+s[i];
        }
    }
    cout<<sum<<endl;
    cout<<odd;
}

