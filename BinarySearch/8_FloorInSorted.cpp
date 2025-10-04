// Given a sorted array and a value x, find the element of the floor of x. The floor of x is the largest element in the array smaller than or equal to x.

// Examples:

// Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 5
// Output: 1
// Explanation: Largest number less than or equal to 5 is 2, whose index is 1

// Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 20
// Output: 6
// Explanation: Largest number less than or equal to 20 is 19, whose index is 6

// Input : arr[] = [1, 2, 8, 10, 10, 12, 19], x = 0
// Output : -1
// Explanation: Since floor doesn't exist, output is -1.

#include <bits/stdc++.h>
using namespace std;
int findFloor(const vector<int>& arr, int target) {
    int n = arr.size();
    int start = 0, end = n - 1;
    int floorIndex = -1; // Initialize floor index to -1 (not found)

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return mid; // Exact match found
        } else if (arr[mid] < target) {
            floorIndex = mid; // Update floor index
            start = mid + 1; // Search in the right half
        } else {
            end = mid - 1; // Search in the left half
        }
    }

    return floorIndex; // Return the index of the floor element or -1 if not found
}
int main() {
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int target = 5;
    int result = findFloor(arr, target);
    if (result != -1) {
        cout << "Floor element index: " << result << endl;
    } else {
        cout << "Floor element does not exist." << endl;
    }
    return 0;
}