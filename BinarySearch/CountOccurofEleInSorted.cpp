// Given a sorted array arr[] and an integer target, find the number of occurrences of target in given array.

// Examples:

// Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
// Output: 4
// Explanation: 2 occurs 4 times in the given array.

// Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
// Output: 0
// Explanation: 4 is not present in the given array.

#include <bits/stdc++.h>
using namespace std;
int countOccurrences(const vector<int>& arr, int target) {
    int n = arr.size();
    int first = -1, last = -1;

    // Finding the first occurrence
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            first = mid; // Update first occurrence
            end = mid - 1; // Move left to find earlier occurrence
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    // If the target is not found, return 0
    if (first == -1) {
        return 0;
    }

    // Finding the last occurrence
    start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            last = mid; // Update last occurrence
            start = mid + 1; // Move right to find later occurrence
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    // The number of occurrences is the difference between last and first indices plus one
    return last - first + 1;
}