// Given a sorted array arr[] of infinite numbers. The task is to search for an element k in the array.

// Examples:

// Input: arr[] = [3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170], k = 10
// Output: 4
// Explanation: 10 is at index 4 in array.

// Input: arr[] = [2, 5, 7, 9], k = 3
// Output: -1
// Explanation: 3 is not present in array.

#include <bits/stdc++.h>
using namespace std;

int findInfiniteArray(const vector<int>& arr, int target) {
    // Start with a small range
    int start = 0;
    int end = 1;

    // Expand the range exponentially until the target is within the range
    while (arr[end] < target) {
        int newStart = end + 1;
        // Double the size of the range
        end = end + (end - start + 1) * 2;
        start = newStart;
    }

    // Perform binary search in the found range
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            start = mid + 1; // Search in the right half
        } else {
            end = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}