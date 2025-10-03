// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]

// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]

// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n=nums.size(),i,k;
        for(i=n-2; i>=0; i--)   //this loop for finding break point index ie peeche se aate hue jab increasing order break ho jaha pe for eg  1 3  5 4 2 break point yaha index 1 hoga
        {
            if(nums[i]<nums[k+1])
            {
                break;
            }
        }
        if(i<0)  //check krte krte index nahi bache to sabjo pura reverse krdo wahi next permutation hoga for eg: 3 2 1=will give 1 2 3
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(k=n-1;k>=0;k--)  //this loop is used ki jab hum peeche se aaye to deke i index ka elemnt jo hume mila hai usse sabse pehla bada element konsa hai---for eg 1 3 5 4 2==ith hamara 3 hai toh peeche se 3 se sabse pehla bada hoga 4 so kth index 3 hue
            {
                if(nums[k]>nums[i])
                {
                    break;
                }
            }
            swap(nums[k],nums[i]); //now just swap ith index elemnt and kth index element
            reverse(nums.begin()+i+1,nums.end()); //finally swapping k baad ith index k baad se reverse krdo pure array ko which will be our answer
        }
        
    }
};



//the intition for doing above apprach can be visualize clearly when be see similar pattern in dictionary