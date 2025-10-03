#include <bits/stdc++.h>
using namespace std;

vector<int> nextLargerElementRight(vector<int>& arr) {
    int n = arr.size();
    vector<int> NLR(n);
    stack<int> stk;
    
    for(int i = n-1; i >= 0; i--) {
        while (!stk.empty() && stk.top() <= arr[i]) {
            stk.pop();
        }
        NLR[i] = (stk.empty()) ? -1 : stk.top();
        stk.push(arr[i]);
    }
    return NLR;
}
//or 
     
    // vector<int> nextLargerElement(vector<int>& arr) {
    // int n = arr.size();
    // vector<int> NLR(n);
    // stack<int> stk;
    
    // for(int i = n-1; i >= 0; i--) {
    //     while (!stk.empty() && stk.top() <= arr[i]) {
    //         stk.pop();
    //     }
    //     NLR[i] = (stk.empty()) ? -1 : stk.top();
    //     stk.push(arr[i]);
    // }
    // return NLR;
    // }



// quick revision notes for Next Greater Element with example:
// 1. The problem involves finding the next greater element for each element in an array.
// 2. The next greater element for an element x is the first greater element on the right side of x in the array.
// 3. If no greater element exists, the next greater element is -1.
// 4. The approach uses a stack to keep track of elements and their next greater elements.
// 5. The time complexity is O(n) where n is the length of the array.
// For the array [4, 5, 2, 10, 8],
// the next greater elements are [5, 10, 10, -1, -1].


//naive approach
// vector<int> nextLargerElementRight(vector<int>& arr) {
//     vector<int> result;
//     int n = arr.size();
//     for(int i = n-1; i >= 0; i--) {
//         int nextGreater = -1; // Default to -1 if no greater element is found
//         for(int j = i + 1; j < n; j++) {
//             if(arr[j] > arr[i]) {
//                 nextGreater = arr[j]; // Found the next greater element
//                 break; // Exit the inner loop
//             }
//         }
//         result.push_back(nextGreater); // Store the next greater element
//     }
//     reverse(result.begin(), result.end()); // Reverse the result to maintain the original order
//     return result;
// }