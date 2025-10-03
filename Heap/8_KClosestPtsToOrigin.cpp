// 973. K Closest Points to Origin
// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
// Input: points = [[1,3],[-2,2]], k = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
// Example 2:
// Input: points = [[3,3],[5,-1],[-2,4]], k = 2
// Output: [[3,3],[-2,4]]
// Explanation: The answer [[-2,4],[3,3]] would also be accepted.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> mxhp; // max heap
        for(int i=0;i<points.size();i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            int dist=x*x+y*y;
            mxhp.push({dist,{x,y}});
            if(mxhp.size()>k)
            {
                mxhp.pop();
            }
        }
        vector<vector<int>>v;
        while(!mxhp.empty())
        {
            v.push_back({mxhp.top().second.first,mxhp.top().second.second});
            mxhp.pop();
        }
        return v;
    }
    //or with structured binding
    // vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    //     priority_queue<pair<int, pair<int, int>>> maxHeap; // max heap
    //     for (const auto& point : points) {
    //         int x = point[0];
    //         int y = point[1];   
    //         int dist = x * x + y * y;
    //         maxHeap.push({dist, {x, y}});
    //         if (maxHeap.size() > k) {
    
    //             maxHeap.pop();
    //         }
    //     }
    //     vector<vector<int>> result;
    //     while (!maxHeap.empty()) {   
    //         auto [dist, coord] = maxHeap.top(); // Structured binding to unpack pair
    //         maxHeap.pop();
    //         result.push_back({coord.first, coord.second});
    //     }
    //     return result;
    // }
};