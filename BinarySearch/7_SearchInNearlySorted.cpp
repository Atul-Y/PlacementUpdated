// Given a sorted integer array arr[] consisting of distinct elements, where some elements of the array are moved to either of the adjacent positions, i.e. arr[i] may be present at arr[i-1] or arr[i+1].
// Given an integer target.  You have to return the index ( 0-based ) of the target in the array. If target is not present return -1.

// Examples : 

// Input: arr[] =  [10, 3, 40, 20, 50, 80, 70], target = 40
// Output: 2 
// Explanation: Output is index of 40 in given array i.e. 2

// Input: arr[] =  [10, 3, 40, 20, 50, 80, 70], target = 90
// Output: -1
// Explanation: 90 is not present in the array.

#include <bits/stdc++.h>
using namespace std;
int searchInNearlySorted(const vector<int>& arr, int target) {
    int n = arr.size();
    int start = 0, end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        // Check if mid is the target
        if (arr[mid] == target) {
            return mid;
        }
        // Check if mid-1 is the target
        if (mid - 1 >= start && arr[mid - 1] == target) {
            return mid - 1;
        }
        // Check if mid+1 is the target
        if (mid + 1 <= end && arr[mid + 1] == target) {
            return mid + 1;
        }

        // If target is less than arr[mid], search in the left half
        if (target < arr[mid]) {
            end = mid - 2; // Exclude mid and mid-1
        } else { // If target is greater than arr[mid], search in the right half
            start = mid + 2; // Exclude mid and mid+1
        }
    }
    return -1; // Target not found
}
int main() {
    vector<int> arr = {-26, -2, -25, 0, -1, 2, 11, 8, 26};
    int target = 11;
    int result = searchInNearlySorted(arr, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}
