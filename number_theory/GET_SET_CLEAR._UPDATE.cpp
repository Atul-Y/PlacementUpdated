#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void getbit(int n, int pos)       
{
   cout<< ((n & (1<<pos))!=0)<<endl;   //n=5=0101 => 1<<pos=2=0100 now n AND 1<<pos i.e is 0101 AND 0100 will give you that at pos what bit was ,here at pos is 1
}

void setbit(int n, int pos)       
{
   cout<< (n | (1<<pos))<<endl;   //n=5=0101 => 1<<pos=1=0100 now n OR 1<<pos i.e is 0101 AND 0010 will set you tha at pos what bit was ,here at pos is 1
}

void clearbit(int n, int pos)     // n=5=0101 pos=2
{                                 // 1<<2=0100
   int mask= ~(1<<pos);          // ~0100=1011
   cout<< (n & mask)<<endl;      // 0101 AND 1011= 0001 =>Hence we cleared the requires pos bit
}

void updatebit(int n, int pos,int value)     
{                               
   int mask= ~(1<<pos);
   n=n & mask;         // clear bit followed by set bit
   cout<< (n | (value<<pos)); 
}

int main()
{
   //  getbit(5,2);
   //  setbit(5,1);
   //  clearbit(5,2);
    updatebit(5,1,1);
    return 0;
}
