#include <bits/stdc++.h>
using namespace std;


//--------------naive approach-O(N^3)----------------
// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0; i<n; i++)
//     {
//         cin>>arr[i];
//     }
//     int maxy=INT_MIN;
//     for(int i=0; i<n; i++)
//     {
//         for(int j=i; j<n; j++)
//         {
//             int sum=0;
//             for(int k=i;k<=j;k++)  // i se j tak k beech ka sum nikalta rahega
//             {
//                 sum=sum+arr[k];
//             }
//             if(sum>maxy)
//             {
//                 maxy=sum;
//             }
//         }
        
//     }
//     cout<<maxy;

// }


//efficiant approach is kadane's aaproach which state  :  Initialize:
//     max_so_far = INT_MIN
//     max_ending_here = 0

// Loop for each element of the array
//   (a) max_ending_here = max_ending_here + a[i]
//   (b) if(max_so_far < max_ending_here)
//             max_so_far = max_ending_here
//   (c) if(max_ending_here < 0)
//             max_ending_here = 0
// return max_so_far


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
       int maxi=INT_MIN;
       int currsum = 0;
       for(int i=0;i<n;i++){
           currsum+=arr[i];       //O(N) and space:O(1)
           if(maxi<currsum)
           {
            maxi=currsum;
           }
           if(currsum<=0)
           {
            currsum=0;
           }
       }
  
    cout<<maxi;
}
