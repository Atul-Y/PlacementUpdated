// Trapping Rain Water Problem

// Input: arr[] = [3, 0, 2, 0, 4]
// Output: 7
// Explanation: We trap 0 + 3 + 1 + 3 + 0 = 7 units.

#include <bits/stdc++.h>
using namespace std;
int trapRainWater(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = height[0]; // Initialize first element of leftMax
    rightMax[n - 1] = height[n - 1];  // Initialize last element of rightMax

    // Fill leftMax array    //no NSL or NSR needed
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    // Fill rightMax array 
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    // Calculate total trapped water
    int totalWater = 0;
    for (int i = 0; i < n; i++) {
        totalWater += min(leftMax[i], rightMax[i]) - height[i];
    }

    return totalWater;
}
int main() {
    vector<int> height = {3, 0, 1, 0, 4, 0, 2};
    int result = trapRainWater(height);
    cout << "Total trapped rain water: " << result << endl; // Output: 10
    return 0;
}


//isme humne NSL or NSR ki jarurat nhi padi kyuki humne leftmax and rightmax array bana liya jisme humne har index pe usse left and right ka max height store kar liya
//ab hum har index pe min(leftmax[i], rightmax[i]) - height[i] se water store kar sakte hai
//isme humne leftmax and rightmax array ko fill karne me O(n) time liya and fir total water calculate karne me O(n) time liya
//isme pehle leftmax ke 0th index pe height[0] store kiya fir uske aage ke index pe leftmax[i] = max(leftmax[i-1], height[i]) se fill kiya
//same rightmax me bhi kiya but reverse direction me ,rightmax[n-1] = height[n-1] se start kiya fir rightmax[i] = max(rightmax[i+1], height[i]) se fill kiya
//toh total time complexity O(n) and space complexity O(n) hai

//table kuch esa hoga   heights:  [3, 0, 1, 0, 4, 0, 2]
//                    leftmax:    [3, 3, 3, 3, 4, 4, 4]
//                    rightmax:   [4, 4, 4, 4, 4, 2, 2]
//                    water:      [0, 3, 2, 3, 0, 2, 0] = total 10
