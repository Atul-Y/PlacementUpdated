#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElementLeft(vector<int>& arr) {
        vector<int> result;
        stack<int> s;
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            if(s.size() == 0){
                result.push_back(-1);
            }
            else if(s.top() < arr[i]){  // Check for next smaller element
                result.push_back(s.top());  
            }
            else{
                while(s.size() > 0 && s.top() >= arr[i])  // Pop elements that are greater than or equal to the current element
                {
                    s.pop();
                }
                if(s.size() == 0){
                    result.push_back(-1);
                }
                else{
                    result.push_back(s.top());
                }
            }
            s.push(arr[i]);  // Push the current element onto the stack
        }
        return result;
    }

// or
// vector<int> nextSmallerElementLeft(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> NSL(n);
//         stack<int> stk;
//         for(int i = 0; i < n; i++) {
//             while (!stk.empty() && stk.top() >= arr[i]) {
//                 stk.pop();
//             }
//             NSL[i] = (stk.empty()) ? -1 : stk.top();
//             stk.push(arr[i]);
//         }
//         return NSL;
//     }

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = nextSmallerElementLeft(arr);
    for(int i : result) {
        cout << i << " ";   //output is -1 4 -1 2 2 
    }
    return 0;
}
// quick revision notes for Next Smallest Element with example:
// 1. The problem involves finding the next smallest element for each element in an array.
// 2. The next smallest element for an element x is the first smaller element on the left side of x in the array.
// 3. If no smaller element exists, the next smallest element is -1.    
// 4. The approach uses a stack to keep track of elements and their next smallest elements.
// 5. The time complexity is O(n) where n is the length of the array
// For the array [4, 5, 2, 10, 8],
// the next smallest elements are [-1,4,-1,2,2].