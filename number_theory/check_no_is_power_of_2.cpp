#include <iostream>
using namespace std;
#include <bits/stdc++.h>
                                   //note: n=6=0110
bool ispowerof2(int n)             //      n-1=5=0101
{
    return (n && !(n & (n-1)));  //n has only one set bit(1) and n-1 will have all set bits after that position
                                // n is any number that is power 2 eg 8=1000  16=10000  
}                               //                                    7=0111  15=01111   
                               // n AND n-1 =0 (always)  => by this we can check that a no is a powerof two or not.

int main()
{
    cout<<ispowerof2(16);
}

