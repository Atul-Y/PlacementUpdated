#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int countofones(int n)    // (n & n-1) has same bits as n except tha rightmost set bit(1)
{                        // n=19=(01011)
    int c=0;             //n-1=18=(01010)
    while(n)             // n AND   n-1 =01011 & 01010= 18 = n(now)   ;c=1
    {                    //now n=18 again  18 & 17=16 = n(now)    ;c=2
        n=n & n-1;       //now n=16 again  16 & 15= 0=n(now)      ;c=3
        c++;             // since our original was 19 and it has 3 ones which is same as value of c(count)
    }
    return c;
}

int main()
{
    cout<<countofones(19);
}