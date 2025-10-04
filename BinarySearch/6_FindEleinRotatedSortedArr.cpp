// Given a sorted and rotated array arr[] of distinct elements, find the index of given key in the array. If the key is not present in the array, return -1.

// Examples:  

// Input: arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 3
// Output: 8
// Explanation: 3 is present at index 8.

// Input: arr[] = [3, 5, 1, 2], key = 6
// Output: -1
// Explanation: 6 is not present.

// Input: arr[] = [33, 42, 72, 99], key = 42
// Output: 1
// Explanation: 42 is found at index 1.

#include <bits/stdc++.h>
using namespace std;
// int searchInRotatedSortedArray(const vector<int>& arr, int target) {
//     int n = arr.size();
//     int start = 0, end = n - 1;

//     while (start <= end) {
//         int mid = start + (end - start) / 2;

//         // Check if mid is the target
//         if (arr[mid] == target) {
//             return mid;
//         }

//         // Determine which part is sorted
//         if (arr[start] <= arr[mid]) {
//             // Left part is sorted
//             if (arr[start] <= target && target < arr[mid]) {
//                 end = mid - 1; // Target is in the left part
//             } else {
//                 start = mid + 1; // Target is in the right part
//             }
//         } else {
//             // Right part is sorted
//             if (arr[mid] < target && target <= arr[end]) {
//                 start = mid + 1; // Target is in the right part
//             } else {
//                 end = mid - 1; // Target is in the left part
//             }
//         }
//     }

//     return -1; // Target not found
// }

//solve using minimum element index
int findMinIndex(const vector<int>& arr) {
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
int binarySearch(const vector<int>& arr, int start, int end, int target) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1; // Target not found
}
int searchUsingMinIndex(const vector<int>& arr, int target) {
    int n = arr.size();
    int minIndex = findMinIndex(arr);

    // If the target is the minimum element
    if (arr[minIndex] == target) {
        return minIndex;
    }

    // Decide which part to search
    if (target >= arr[0]) {
        // Search in the left part
        return binarySearch(arr, 0, minIndex - 1, target);
    } else {
        // Search in the right part
        return binarySearch(arr, minIndex + 1, n - 1, target);
    }
}
int main() {
    vector<int> arr = {1,3};
    int target = 3;
    int result = searchUsingMinIndex(arr, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}

