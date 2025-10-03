

// coditions-in this question we cant make changes to array elements
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

    unordered_map<int ,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }

    for(auto i:mp)
    {
        if(i.second>1)
        {
            cout<<i.first;
            break;
        }
    }
}


//-----------brute force approach-----------

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int ind = 0;
		
// 		// sort the vector
//         sort(nums.begin(),nums.end());
//         for(int i = 0; i < nums.size() - 1; i++)
//         {
// 			// if two consecutive elements are equal
// 			// you have find a duplicate
// 			// break the loop
//             if(nums[i] == nums[i+1])
//             {
//                 ind = nums[i];
//                 break;
//             }
//         }
//         // return duplicate value
//         return ind;
//     }
// };


//--------------APPROACH 3 USING CNT VECTOR---------------

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
// 		// initialise cnt vector of size nums with 0
//         vector<int> cnt(nums.size(),0);
//         int ind =  0;
		
// 		// store the cnt of each value in the cnt vector
//         for(int i = 0; i<nums.size(); i++)
//         {
//             cnt[nums[i]]++;
//         }
        
//         for(int i = 0; i<cnt.size(); i++)
//         {
// 			// if cnt[i] > 1
// 			// this means that element occur more than once in nums
// 			// we have to return i
//             if(cnt[i] > 1)
//             {
//                 ind  = i;
//                 break;
//             }
//         }
        
//         return ind;
//     }
// };