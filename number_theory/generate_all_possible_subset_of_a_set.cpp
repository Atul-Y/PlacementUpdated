#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void possiblesubset(int arr[],int n)      // 2^n can be written as 1<<n(understant from vidio)
{                                         //pehle saare 0 se 2^n tak binary representation krke deko ,fir ab usme jaha jaha 1 aaya hai wahi hamare subset hohe
    for(int i=0;i<(1<<n);i++)            // for eg {1,2,3} total repres will be 2^n  000,001,010,011,100,101,110,111 => ab isme jis jis place me 1 hai bs wahi no given set se print krte chalo toh saare subset mil jaenge
    {
        for(int j=0;j<n;j++)
        {
            if(i & (1<<j))
            {
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    int arr[3]={1,2,3};
    possiblesubset(arr,3);

    return 0;
}