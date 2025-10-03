// Given an array of integers and two numbers k1 and k2. Find the sum of all elements between given two k1'th and k2'th smallest elements of the array. It may be assumed that (1 <= k1 < k2 <= n) and all elements of array are distinct.

// Examples : 

// Input : arr[] = [20, 8, 22, 4, 12, 10, 14] k1 = 3,  k2 = 6  
// Output : 26          
//          3rd smallest element is 10. 6th smallest element 
//          is 20. Sum of all element between k1 & k2 is
//          12 + 14 = 26

// Input : arr[] = [10, 2, 50, 12, 48, 13], k1 = 2, k2 = 6 
// Output : 73 
#include <bits/stdc++.h>
using namespace std;
int sumBetweenTwoKthSmallest(vector<int> &arr, int k1, int k2)
{
    priority_queue<int> mxhp; // max heap
    for (int i = 0; i < arr.size(); i++)
    {
        mxhp.push(arr[i]);
        if (mxhp.size() > k2 - 1) // we need to store elements till k2-1 smallest element
        {
            mxhp.pop();
        }
    }
    int sum = 0;
    while (mxhp.size() > 1) // we need to sum elements between k1 and k2 so we will pop till size becomes k1+1
    {
        sum += mxhp.top();
        mxhp.pop();
    }
    return sum;
}