// Given an array arr[] of integers and an integer k, your task is to find the maximum value for each contiguous subarray of size k. The output should be an array of maximum values corresponding to each contiguous subarray.

// Examples : 

// Input: arr[] = [1, 2, 3, 1, 4, 5, 2, 3, 6], k = 3
// Output: [3, 3, 4, 5, 5, 5, 6] 
// Explanation: 
// 1st contiguous subarray = [1 2 3] max = 3
// 2nd contiguous subarray = [2 3 1] max = 3
// 3rd contiguous subarray = [3 1 4] max = 4
// 4th contiguous subarray = [1 4 5] max = 5
// 5th contiguous subarray = [4 5 2] max = 5
// 6th contiguous subarray = [5 2 3] max = 5
// 7th contiguous subarray = [2 3 6] max = 6

// Input: arr[] = [5, 1, 3, 4, 2, 6], k = 1
// Output: [5, 1, 3, 4, 2, 6]
// Explanation: When k = 1, each element in the array is its own subarray, so the output is simply the same array.

// Input: arr[] = [1, 3, 2, 1, 7, 3], k = 3
// Output: [3, 3, 7, 7]


//brute force approach
// 1. Iterate through the array with two nested loops.
// 2. The outer loop will fix the starting point of the subarray.
// 3. The inner loop will iterate through the next k elements to find the maximum.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> maxOfSubarrays(vector<int>& arr, int k) {
    vector<int> result;
    int n = arr.size();

    for (int i = 0; i <= n - k; i++) {
        int maxVal = arr[i];
        for (int j = i + 1; j < i + k; j++) {
            maxVal = max(maxVal, arr[j]);
        }
        result.push_back(maxVal);
    }

    return result;
}


// Optimized approach using sliding window technique
// 1. Use a deque to store indices of elements in the current window.
// 2. Maintain the deque such that the front always contains the index of the maximum element in the current window.
// 3. Slide the window across the array, updating the deque and result accordingly.
#include <bits/stdc++.h>
using namespace std;

vector<int> maxInSubarrays(vector<int>& arr, int k) {
    int i = 0, j = 0;
    int n = arr.size();
    vector<int> result;
    deque<int> dq;  // Stores indices of useful elements in window

    while (j < n) {
        // Remove smaller elements from the back of deque
        while (!dq.empty() && arr[dq.back()] < arr[j]) {
            dq.pop_back();
        }

        // Add current element index
        dq.push_back(j);

        // If window size < k, just move j
        if (j - i + 1 < k) {
            j++;
        }
        // When window size hits k
        else if (j - i + 1 == k) {
            // Front of deque is the largest element in window
            result.push_back(arr[dq.front()]);

            // Remove element going out of window
            if (dq.front() == i) {
                dq.pop_front();
            }

            // Slide the window
            i++;
            j++;
        }
    }

    return result;
}
