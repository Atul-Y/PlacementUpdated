// Find the minimum difference element in a sorted array
// Given an array of integers sorted in ascending order, and a target value, find the element in the array that has minimum difference with the target value.

// Example 1:

// Input: a[] = [2, 5, 10, 12, 15], target = 6
// Output: 5
// Explanation: The difference between the target value '6' and '5' is the minimum. 


#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

int findMinDiffElement(vector<int>& arr, int target) {
    int n = arr.size();
    int start = 0, end = n - 1;

    // Edge cases: if target is smaller than smallest element
    if (target <= arr[0]) return arr[0];
    // If target is greater than largest element
    if (target >= arr[n - 1]) return arr[n - 1];

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return arr[mid]; // exact match
        }
        else if (arr[mid] < target) {
            start = mid + 1; // search right
        }
        else {
            end = mid - 1; // search left
        }
    }

    // At this point, end < start.
    // 'end' is the floor (largest smaller element),
    // 'start' is the ceil (smallest greater element).
    if (abs(arr[start] - target) < abs(arr[end] - target)) {
        return arr[start];
    } else {
        return arr[end];
    }
}

int main() {
    vector<int> a = {2, 5, 10, 12, 15};
    int target = 6;

    cout << findMinDiffElement(a, target) << endl; // Output: 5
    return 0;
}
