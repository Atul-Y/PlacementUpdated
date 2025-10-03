#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// void primeSieve(int n)
// {
//     int prime[100]={0};
//     for(int i=2;i<=n;i++)
//     {
//         if(prime[i]==0)
//         {
//             for(int j=i*i;j<=n;j=j+i)
//             {
//                 prime[j]=1;
//             }
//         }

//     }

//     for(int i=2;i<=n;i++)
//     {
//         if(prime[i]==0)
//         {
//             cout<<i<<" ";
//         }
//     }
//     cout<<endl;
// }

// int main()
// {
//     primeSieve(30);
//     return 0;
// }



//prime factorization using seive
void primefactorbySive(int n)
{
    int spf[100]={0};
    for(int i=2;i<=n;i++)
    {
        spf[i]=i;
    }

    for(int i=2;i<=n;i++)
    {
        if(spf[i]==i)
        {
            for(int j=i*i;j<=n;j=j+i)
            {
                if(spf[j]==j)
                {
                   spf[j]=i ;
                }
            }
        }
    }
    while(n!=1)
    {
        cout<<spf[n]<<" ";
        n=n/spf[n];
    }

}

int main()
{
    primefactorbySive(30);
    return 0;
}