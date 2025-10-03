 // arr[] = {1, -1, 3, 2, -7, -5, 11, 6 }
// Output :  1  3  2  11  6  -1  -7  -5
                                       

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
    //remeber order shoud be same 
//     int t[n]; // t is temporary array
//        int j=0;
//        for(int i=0; i<n; i++){
//            if(arr[i]>=0)
//                t[j++]=arr[i];
//        }
//        for(int i=0; i<n; i++){
//            if(arr[i]<0)
//                t[j++]=arr[i];
//        }
//        for(int i=0; i<n; i++){
//                arr[i]=t[i];
//        }

//        for(int i=0; i<n; i++)
//        {
//         cout<<arr[i]<<" ";
//        }
// }


//------optimize apraoch----------optimize
//  O(n) and space is O(1)-----------


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

    int i=-1;
    for(int j=0;j<n;j++)
    {
        if(arr[j]<0)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}