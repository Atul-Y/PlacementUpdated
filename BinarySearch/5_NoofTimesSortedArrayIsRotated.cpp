// Number of Times a Sorted array is Rotated
// Input: arr[] = [15, 18, 2, 3, 6, 12]
// Output: 2
// Explanation: 
// Original sorted array = [2, 3, 6, 12, 15, 18]
// After 2 right rotations → [15, 18, 2, 3, 6, 12]  

//key concept: Binary Search
//formula: no of rotations = index of minimum element

#include <bits/stdc++.h>
using namespace std;
int countRotations(const vector<int>& arr) {
    int n = arr.size();
    int start = 0, end = n - 1;

    while (start <= end) {
        // If the array is already sorted, return the start index
        if (arr[start] <= arr[end]) {
            return start;
        }

        int mid = start + (end - start) / 2;
        int next = (mid + 1) % n; // To handle the circular nature
        int prev = (mid - 1 + n) % n; // To handle the circular nature

        // Check if mid is the minimum element
        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev]) {
            return mid;
        }

        // Decide which part to search next
        if (arr[start] <= arr[mid]) {
            // Left part is sorted, so the minimum must be in the right part
            start = mid + 1;
        } else {
            // Right part is sorted, so the minimum must be in the left part
            end = mid - 1;
        }
    }
    return 0; // This line should never be reached if the input array is a rotated sorted array
}
