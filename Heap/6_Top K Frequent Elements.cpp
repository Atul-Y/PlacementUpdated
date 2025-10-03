// Top K Frequent Elements
// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

#include <bits/stdc++.h>
using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }

    // Min-heap to store the top k frequent elements
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (const auto& entry : freqMap) {
        minHeap.push({entry.second, entry.first}); // Push frequency and element
        if (minHeap.size() > k) {
            minHeap.pop(); // Remove the least frequent element if size exceeds k
        }
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second); // Extract the element
        minHeap.pop();
    }
    return result;
}
int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);
    cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl; // Output: [1, 2]
    return 0;
}
// Humne frequency map banaya jisme har element ki frequency store ki ie{element, frequency}
// Fir min-heap banaya jisme hum top k frequent elements ko store karenge aur min-heap me map ka pair ko reverse order me store karenge ie {frequency, element} taki heap frequency ke basis pe sort ho sake
// Jab bhi heap ka size k se jada hoga hum least frequent element ko remove kar denge
// Finally heap me jo elements bachege wahi top k frequent elements honge
