// N = 6
// arr[] = 7 10 4 3 20 15
// K = 3
// Output : 7
// Explanation :
// 3rd smallest element in the given 
// array is 7.


//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
    int kthSmallest(int arr[], int l, int r, int k) 
    {
        priority_queue<int> mxhp;
        for(int i=l;i<=r;i++)
        {
            mxhp.push(arr[i]);
            if(mxhp.size()>k)
            {
                mxhp.pop();
            }
        }
        return mxhp.top();
        //code here
    }

// { Driver Code Starts.
 
int main()
{
    int test_case; 
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        cout<<
        kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends


//-----we can also solve by sorting and returning k-1-----------