#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int binary2dec(int n)
{
    int i=0,rem=0,dec=0;
    while(n!=0)
    {
        rem=n%10;
        dec=dec+rem*pow(2,i);
        n=n/10;
        i++;
    }
    return dec;
}

int bianary2octal(int n)
{
    int val,i=1,lastdigit,octal=0;
    while(n!=0)
    {
        lastdigit=n%1000;
        val=binary2dec(lastdigit);
        octal=octal+val*i;
        i=i*10;
        n=n/1000;
    }
    return octal;
}

int dec2bin(int num)
{
    int i=1,rem=0,bin=0;
    while(num!=0)
    {
        rem=num%2;
        bin=bin+rem*i;
        i=i*10;
        num=num/2;  
    }
    return bin;
}

int octal2binary(int n)
{
    int val,i=1,lastdigit,bin=0;
    while(n!=0)
    {
        lastdigit=n%10;
        val=dec2bin(lastdigit);
        bin=bin+val*i;
        i=i*10;
        n=n/10;
    }
    return bin;
}

int main()
{
    int n1=10001;
    int n2=54;
    cout<<bianary2octal(n1)<<endl;
    cout<<octal2binary(n2);
    return 0;
}