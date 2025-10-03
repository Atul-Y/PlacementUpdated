// N = 5
// arr[]= {0 2 1 2 0}
// Output:
// 0 0 1 2 2
// Explanation:
// 0s 1s and 2s are segregated 
// into ascending order.

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }

//     int cnt0=0,cnt1=0,cnt2=0;

//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]==0)
//         {
//             cnt0++;
//         }
//         else if(arr[i]==1)
//         {
//             cnt1++;
//         }
//         else
//         {
//             cnt2++;
//         }
//     }

//     for(int i=0;i<cnt0;i++)
//     {
//         arr[i]=0;
//     }
//     for(int i=cnt0;i<cnt0+cnt1;i++)
//     {
//         arr[i]=1;
//     }
//     for(int i=cnt0+cnt1;i<n;i++)
//     {
//         arr[i]=2;
//     }

//     for(int i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
    
// }

//the above approach takes 0(2N) 

//optimize approach is below which is called dutch national flag algorithm


#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main()                                    
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int l=0;
    int mid=0;
    int r=n-1;
    while(mid<=r)
    {
        if(arr[mid]==0)
        {
            swap(arr[mid],arr[l]);
            mid++,l++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid],arr[r]);
            r--;
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
}