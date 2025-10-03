#include <bits/stdc++.h>
using namespace std;

    int getMaxAreaHistogram(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n), right(n);
    stack<int> s;

    // Fill left array NSL
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[i] <= heights[s.top()]) { // Check for next smaller element
            s.pop();
        }
        left[i] = (s.empty()) ? -1 : s.top();  // If stack is empty, no smaller element to the left
        s.push(i); // Push current index onto the stack
    }

    // Clear stack for right calculation
    while (!s.empty()) {
        s.pop();
    }

    // Fill right array NSR
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && heights[i] <= heights[s.top()]) {
            s.pop();
        }
        right[i] = (s.empty()) ? n : s.top(); // If stack is empty,right[i] is n (no smaller element to the right) 
        s.push(i);
    }

    // Calculate maximum area
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;  // Width is the distance between the nearest smaller elements on both sides 
        maxArea = max(maxArea, heights[i] * width); //
    }

    return {maxArea};
}

//naive approach
// int getMaxAreaHistogram(vector<int>& heights) {
//     int n = heights.size();
//     int maxArea = 0;
//     for (int i = 0; i < n; i++) {
//         int minHeight = heights[i];
//         for (int j = i; j < n; j++) {
//             minHeight = min(minHeight, heights[j]);
//             int width = j - i + 1;
//             maxArea = max(maxArea, minHeight * width);
//         }
//     }
//     return maxArea;
// }

int main() {
    vector<int> heights = {60, 20, 50, 40, 10, 50, 60};
    int result = getMaxAreaHistogram(heights);
    cout << "Maximum area in histogram: " << result << endl; // Output: 100
    return 0;
}

// quick revision notes for Maximum Area in Histogram with example:
//this is based on next smallest element to left and right
// 1. sabse pehle next smallest element to left and right nikalna hai
// 2. left[i] mein NSL ka index store karna hai with empty case -1
// 3. right[i] mein NSR ka index store karna hai with empty case n (important change from general NSR) 
// 4. fir area nikalna hai har index ke liye using formula: area = heights[i] * (right[i] - left[i] - 1)
// 5. max area return karna hai
 //table kuch esa hoga   heights:  [60, 20, 50, 40, 10, 50, 60]
    //                    left:    [-1, -1,  1,  1, -1,  4,  5] 
    //                    right:   [1,   4,  3,  4,  7,  7,  7]
    //                    width:   [1,   4,  1,  2,  7,  2,  1]
    //                    area:    [60, 80, 50, 80, 70,100, 60]




