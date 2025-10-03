// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
 
//  int unique(int arr[],int n)
//  {
//      int xorsum=0;
//      for(int i=0;i<n;i++)
//      {
//          xorsum=xorsum^arr[i];

//      }
//      return xorsum;
//  }

// int main()
// {
//     int arr[]={1,2,3,1,2,3,4};
//     cout<<unique(arr,7);
// }

// wap to find two unique no in an array where all except two no are present twice.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int setBit(int n,int pos)
{
    return (n & (1<<pos))!=0;
}
 
 void unique2(int arr[],int n)
 {
     int xorsum=0;                   
     for(int i=0;i<n;i++)
     {
         xorsum=xorsum^arr[i];        //1

     }
     int tempxor=xorsum;
     int setbit=0;
     int pos=0;
     while(setbit!=1)
     {
         setbit=xorsum & 1;
         pos++;                  //xorsum me rightmost setbit ki pos find kro
         xorsum=xorsum>>1;  
     }

     int newxor=0;
     for(int i=0;i<n;i++)
     {
         if(setBit(arr[i],pos-1))          //ab wo pos me given elements me deko unme uss pos me setbit hai to unka xorsum kro 
         {
           newxor=newxor^arr[i];          //final newxorsum hame pehla uniique no dega
         }
     }
     cout<<newxor<<" ";
     cout<<(tempxor^newxor);              //pehle step 1 me joxorsum tha usse newxorum se xor krdo to dusra xor sum mil jaega
 }

int main()
{
    int arr[]={1,2,3,5,2,3,4,1};
    unique2(arr,8);
    
    return 0;
}
