// Given a sorted array arr[] and an integer x, find the index (0-based) of the smallest element in arr[] that is greater than or equal to x. This element is called the ceil of x. If such an element does not exist, return -1.

// Note: In case of multiple occurrences of ceil of x, return the index of the first occurrence.

// Examples

// Input: arr[] = [1, 2, 8, 10, 11, 12, 19], x = 5
// Output: 2
// Explanation: Smallest number greater than 5 is 8, whose index is 2.
// Input: arr[] = [1, 2, 8, 10, 11, 12, 19], x = 20
// Output: -1
// Explanation: No element greater than 20 is found. So output is -1.
// Input: arr[] = [1, 1, 2, 8, 10, 11, 12, 19], x = 0
// Output: 0
// Explanation: Smallest number greater than 0 is 1, whose indices are 0 and 1. The index of the first occurrence is 0.

#include <bits/stdc++.h>
using namespace std;
int findCeilIndex(const vector<int>& arr, int target) {
    int n = arr.size();
    int start = 0, end = n - 1;
    int ceilIndex = -1; // Initialize ceil index to -1 (not found)

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return mid; // Exact match found
        } else if (arr[mid] < target) {
            start = mid + 1; // Search in the right half
        } else {
            ceilIndex = mid; // Update ceil index
            end = mid - 1; // Search in the left half
        }
    }

    return ceilIndex; // Return the index of the ceil element or -1 if not found
}