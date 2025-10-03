#include <bits/stdc++.h>
using namespace std;


//  1> loop kro aur deko ki koi decrease ki comdition satify kr raha hai agar kr raha hai to decrease nahi to increase krdo 
//  2>  ab *max_element() aur *min_element() ka diff krdo
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i=0; i<n; i++)    //WRONG ! as we cant know when to subtract k aur when to add k
    {
        if(arr[i]>k)
        {
            arr[i]=arr[i]-k;
        }
        else
        {
            arr[i]=arr[i]+k;
        }
    }

    int ans=*max_element(arr,arr+n)-*min_element(arr,arr+n);
    cout<<ans;

}

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int maxy=arr[n-1];
    int miny=arr[0];
    int res=maxy-miny;

    for(int i=0; i<n; i++)
    {
        if(arr[i]-k<0) //we do this to check negative na ho jaye k minus krne me (condition given hai question me)  // if on subtracting k we got negative then continue
        continue;

        miny=min(arr[0]+k,arr[i]-k);//---minimizing d(from left)  //minimum element when we add k to whole array
        maxy=max(arr[i-1]+k,arr[n-1]-k);//---maximizing---c(from right)    //maximum element when we substract k from whole array

        res=min(res,maxy-miny);
    }
    cout<<res;

} 