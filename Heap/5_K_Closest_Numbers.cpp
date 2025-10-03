// 658. Find K Closest Elements
// Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
// An integer a is closer to x than an integer b if:
// |a - x| < |b - x|, or
// |a - x| == |b - x| and a < b
// Example 1:
// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]
// Example 2:
// Input: arr = [1,1,2,3,4,5], k = 4, x = -1
// Output: [1,1,2,3]
#include <bits/stdc++.h>
using namespace std;

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    vector<int> v;
    priority_queue<pair<int, int>> mxhp;

    for (int i = 0; i < arr.size(); i++)
    {
        mxhp.push({abs(arr[i] - x), arr[i]});
        if (mxhp.size() > k)
        {
            mxhp.pop();
        }
    }

    while (!mxhp.empty())
    {
        v.push_back(mxhp.top().second);
        mxhp.pop();
    }

    sort(v.begin(), v.end()); // extra said as per question to return in ascending order
    return v;
}

//revision notes
//closest element to x means minimum absolute difference of element with x for eg table below
//Input: arr = [1,2,3,4,5], k = 4, x = 3
// element  | 1 | 2 | 3 | 4 | 5 |
// minus x  | 3 | 3 | 3 | 3 | 3 |
// abs diff | 2 | 1 | 0 | 1 | 2 |
// so we need to find k elements with minimum absolute difference with x

