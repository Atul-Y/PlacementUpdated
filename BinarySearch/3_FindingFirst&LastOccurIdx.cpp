// Given a sorted array arr[] with possibly some duplicates, the task is to find the first and last occurrences of an element x in the given array.

// Note: If the number x is not found in the array then return both the indices as -1.

// Examples: 

// Input : arr[] = [1, 3, 5, 5, 5, 5, 67, 123, 125], x = 5
// Output : 2 5
// Explanation: First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5

// Input : arr[] = [1, 3, 5, 5, 5, 5, 7, 123, 125 ], x = 7
// Output : 6 6
// Explanation: First and last occurrence of 7 is at index 6

// Input: arr[] = [1, 2, 3], x = 4
// Output: -1 -1
// Explanation: No occurrence of 4 in the array, so, output is [-1, -1]

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector < int > findFirstAndLastOccurrence(vector < int > & nums, int target) {
        int n = nums.size();
        int first = -1, last = -1;

        // Finding the first occurrence
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                first = mid; // Update first occurrence
                end = mid - 1; // Move left to find earlier occurrence
            } else if (target > nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        // Finding the last occurrence
        start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                last = mid; // Update last occurrence
                start = mid + 1; // Move right to find later occurrence
            } else if (target > nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        vector<int> ans = {first,last};
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> arr = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int x = 5;
    vector<int> result = sol.findFirstAndLastOccurrence(arr, x);
    cout << "First and Last Occurrence of " << x << " is: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}