// Sort Array by Increasing Frequency
// Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
// Return the sorted array.
// Example 1:
// Input: nums = [1,1,2,2,2,3]
// Output: [3,1,1,2,2,2]
// Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

#include <bits/stdc++.h>
using namespace std;
struct Compare {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
        if (a.first == b.first) {
            return a.second < b.second; // larger number first
        }
        return a.first > b.first; // smaller frequency first
    }
};
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mnhp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> mnhp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            mnhp.push({it.second,it.first});
        }
        vector<int>v;
        while(!mnhp.empty())
        {
            for(int i=1;i<=mnhp.top().first;i++)
            {
                v.push_back(mnhp.top().second);
            }
            mnhp.pop();
        }
        return v;
    }
  
    //or with structured binding
    // vector<int> frequencySort(vector<int>& nums) {
    //     unordered_map<int,int> mp;
    //     for (int n : nums) mp[n]++;
    //     priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
    //     for (auto& it : mp) {
    //         pq.push({it.second, it.first}); // (frequency, number)
    //     }
    //     vector<int> result;
    //     while (!pq.empty()) {
    //         auto [freq, num] = pq.top();  // Structured binding to unpack pair
    //         pq.pop();
    //         for (int i = 0; i < freq; i++) {
    //             result.push_back(num);
    //         }
    //     }
    //     return result;
    // }

    
private:
    struct Compare {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first == b.first) {
                return a.second < b.second; // larger number first
            }
            return a.first > b.first; // smaller frequency first
        }
    };
};
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 2, 3};
    vector<int> result = sol.frequencySort(nums);
    cout << "Sorted array by frequency: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl; // Output: [3, 1, 1, 2, 2, 2]
    return 0;
}
// Humne frequency map banaya jisme har element ki frequency store ki ie{element, frequency}
// Fir min-heap banaya jisme hum elements ko frequency ke basis pe sort karenge
// Humne custom comparator banaya jisme hum frequency ascending and value descending pe sort karenge
// Finally heap se elements ko nikal ke result array me store karenge
// Key ideas: iss question me hme comparator or structured binding ache se sichne ko milta hai