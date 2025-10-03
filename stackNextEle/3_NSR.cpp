#include <bits/stdc++.h>
using namespace std;

// vector<int>nextSmallestRight(vector<int>& arr) {
//         vector<int> result;
//         stack<int> s;
//         int n = arr.size();
//         for(int i = n-1; i >= 0; i--)
//         {
//             if(s.size() == 0){
//                 result.push_back(-1);
//             }
//             else if(s.top() < arr[i]){
//                 result.push_back(s.top());  
//             }
//             else{
//                 while(s.size() > 0 && s.top() >= arr[i]) 
//                 {
//                     s.pop();
//                 }
//                 if(s.size() == 0){
//                     result.push_back(-1);
//                 }
//                 else{
//                     result.push_back(s.top());
//                 }
//             }
//             s.push(arr[i]);
//         }
//         reverse(result.begin(), result.end()); 
//         return result;
//     }

vector<int> nextSmallestRight(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSR(n);
        stack<int> stk;
        for(int i = n-1; i >= 0; i--) {
            while (!stk.empty() && stk.top() >= arr[i]) {
                stk.pop();
            }
            NSR[i] = (stk.empty()) ? -1 : stk.top();
            stk.push(arr[i]);
        }
        return NSR;
    }

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = nextSmallestRight(arr);
    for(int i : result) {
        cout << i << " "; // Output: 2 2 -1 8 -1
    }
    return 0;
}
// or



// quick revision notes for Next Smallest Element with example:
// 1. The problem involves finding the next smallest element for each element in an array.
// 2. The next smallest element for an element x is the first smaller element on the right side of x in the array.
// 3. If no smaller element exists, the next smallest element is -1.
// 4. The approach uses a stack to keep track of elements and their next smallest elements.
// 5. The time complexity is O(n) where n is the length of the array
// For the array [4, 5, 2, 10, 8],
// the next smallest elements are [2, 2, -1, 8, -1].
