// Maximum size rectangle binary sub-matrix with all 1s
// Given a 2d binary matrix mat[][], the task is to find the maximum size rectangle binary-sub-matrix with all 1's. 

// Examples: 

// Input: 
// mat = [
//    [0, 1, 1, 0],
//    [1, 1, 1, 1],
//    [1, 1, 1, 1],
//    [1, 1, 0, 0] ]

// Output : 8
// Explanation : The largest rectangle with only 1's is from (1, 0) to (2, 3) which is
// [1, 1, 1, 1]
// [1, 1, 1, 1]

#include <bits/stdc++.h>
using namespace std;
int getMaxAreaHistogram(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n), right(n);
    stack<int> s;

    // Fill left array
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] >= heights[i]) { // Check for next smaller element
            s.pop();
        }
        left[i] = (s.empty()) ? -1 : s.top();  // If stack is empty, no smaller element to the left
        s.push(i); // Push current index onto the stack
    }

    // Clear stack for right calculation
    while (!s.empty()) {
        s.pop();
    }

    // Fill right array
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
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

int maximalRectangle(vector<vector<int>>& matrix) {
    if(matrix.empty()) return 0;
    int maxArea = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0); // Initialize heights for histogram

    for(int i = 0; i < rows; i++) {   
        for(int j = 0; j < cols; j++) {
            // Update the heights array
            if(matrix[i][j] == 1) {
                heights[j] += 1;
            } else {
                heights[j] = 0;
            }
        }
        // Calculate the maximum area for the current histogram
        maxArea = max(maxArea, getMaxAreaHistogram(heights));
    }

    return maxArea;
}
int main() {
    vector<vector<int>> matrix = {
        {0, 1, 1},
        {1, 1, 1},
        {0, 1, 1},
    };
    int result = maximalRectangle(matrix);
    cout << "Maximum size rectangle binary sub-matrix with all 1s: " << result << endl; // Output: 8
    return 0;
}


// quick revision notes for Maximum Area in Histogram with example:
//ye MAH ka hi extension hai 
//isme matrix ki hum har row ko histogram maan ke uska MAH nikalenge
//har row ko histogram banane ke liye hum uske upar jitne bhi 1s hai unko count karenge
//jaise hi 0 aayega hum usko 0 kar denge
//fir jo bhi heights ka array banega uska MAH nikalenge
//esahi hum har ek row (heights) ke liye MAH nikal ke uska max lenge .