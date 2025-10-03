// Naive Approach - O(n k) Time and O(1) Space

#include <iostream>
#include <vector>
#include <climits>

//notes for brute force solution
// 1. Iterate through the array with two nested loops.
// 2. The outer loop will fix the starting point of the subarray.
// 3. The inner loop will iterate through the next k elements to calculate the sum.
// 4. Keep track of the maximum sum found during these iterations.

// using namespace std;
// int maxSum(vector<int>& arr, int k) {
//     int n = arr.size();
//     int maxSum = INT_MIN;

//     for (int i = 0; i <= n - k; i++) {
//         int currentSum = 0;
//         for (int j = i; j < i + k; j++) {
//             currentSum += arr[j];
//         }
//         maxSum = max(maxSum, currentSum);
//     }

//     return maxSum;
// }


// int main() {
//     vector<int> arr = {1, 4, 2, 10, 2, 3, 1, 0, 20};
//     int k = 4;

//     cout << maxSum(arr, k) << endl;
//     return 0;
// }


// Time Complexity: O(n), to iterate n times.
// Auxiliary Space: O(k) , to store k elements inside queue.

// Using Queue:
// We can use queue structure to calculate max or min sum of a subarray of size k.

// Algorithm:
// First create an queue structure and push k elements inside it and calculate the sum of the elements (let's say su) during pushing.
// Now create a max/min variable (let's say m) with value INT_MIN for max value or INT_MAX for min value.
// Then iterate using loop from kth position to the end of the array.
// During each iteration do below steps:
// First subtract su with the front element of the queue.
// Then pop it from the queue.
// Now, push the current element of the array inside queue and add it to the su.
// Then compare it with the value m for max/min.
// Now, print the current m value.


// O(n) solution for finding maximum sum of
// a subarray of size k with O(k) space

// #include <bits/stdc++.h>
// using namespace std;

// // Returns maximum sum in a subarray of size k.
// int maxSum(int arr[], int n, int k)
// {
//     // k must be smaller than n
//     if (n < k) {
//         cout << "Invalid";
//         return -1;
//     }

//     // Create Queue
//     queue<int> q;

//     int m = INT_MIN;
//     int su = 0;

//     // Compute sum of first k elements and also
//     // store then inside queue
//     for (int i = 0; i < k; i++) {
//         q.push(arr[i]);
//         su += arr[i];
//     }

//     for (int i = k; i < n; i++) {
//       	m = max(m, su);
//         su -= q.front();
//         q.pop();
//         q.push(arr[i]);
//         su += arr[i];
//     }
// 	m = max(m, su);
//     return m;
// }

// int main()
// {
//     int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
//     int k = 4;
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << maxSum(arr, n, k);
//     return 0;
// }

// Optimized  Solution (Space Optimization) :
// Using the Sliding Window Technique - O(n) Time and O(1) Space

// An Efficient Solution is based on the fact that sum of a subarray (or window) of size k can be obtained in O(1) time using the sum of the previous subarray (or window) of size k. Except for the first subarray of size k, for other subarrays, we compute the sum by removing the first element of the last window and adding the last element of the current window.


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMaxSumSubarray(vector<int>& arr, int k) {
    int i = 0, j = 0; // i = window start, j = window end
    int windowSum = 0;
    int maxSum = INT_MIN;

    while (j < arr.size()) {
        // Add current element to the window
        windowSum += arr[j];

        // If window size is less than k, expand the window
        if (j - i + 1 < k) {
            j++;
        }
        // If window size is exactly k
        else if (j - i + 1 == k) {
            // Check if it's the maximum so far
            maxSum = max(maxSum, windowSum);

            // Slide the window forward
            windowSum -= arr[i]; // Remove element going out of window
            i++;
            j++;
        }
    }

    return maxSum;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << "Maximum sum of subarray of size " << k << " is: " << findMaxSumSubarray(arr, k) << endl;
    return 0;
}
