// Given an array arr[] where no two adjacent elements are same, find the index of a peak element. An element is considered to be a peak element if it is strictly greater than its adjacent elements. If there are multiple peak elements, return the index of any one of them.

// Note: Consider the element before the first element and the element after the last element to be negative infinity.

// Examples:

// Input: arr[] = [1, 2, 4, 5, 7, 8, 3]
// Output: 5
// Explanation: arr[5] = 8 is a peak element because arr[4] < arr[5] > arr[6].

// Input: arr[] = [10, 20, 15, 2, 23, 90, 80]
// Output: 1
// Explanation: Element 20 at index 1 is a peak since 10 < 20 > 15. Index 5 (value 90) is also a peak, but returning any one peak index is valid.

#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return 0;

    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid > 0 && mid < n - 1)
        {
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else if (nums[mid] > nums[mid - 1])
            {
                start = mid + 1; // agar piche wala chota hai to right side move kro
            }
            else
            {
                end = mid - 1;
            }
        }
        else if (mid == 0)
        {
            return nums[0] > nums[1] ? 0 : 1;
        }
        else if (mid == n - 1)
        {
            return nums[n - 1] > nums[n - 2] ? n - 1 : n - 2;
        }
    }

    return 0;
}