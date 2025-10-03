#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreatestElementLeft(vector<int>& arr) {
        vector<int> result;
        stack<int> s;
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            if(s.size() == 0){
                result.push_back(-1);
            }
            else if(s.top() > arr[i]){
                result.push_back(s.top());  
            }
            else{
                while(s.size() > 0 && s.top() <= arr[i]) 
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
            s.push(arr[i]);
        }
        return result;
    }

    int main() {
        vector<int> arr = {4, 5, 2, 10, 8};
        vector<int> result = nextGreatestElementLeft(arr);
        for(int i : result) {
            cout << i << " ";
        }
        return 0;
    }

    //or 
// vector<int> nextGreaterElement(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> NGL(n);
//         stack<int> stk;
        
//         for(int i = 0; i < n; i++) {
//             while (!stk.empty() && stk.top() <= arr[i]) {
//                 stk.pop();
//             }
//             NGL[i] = (stk.empty()) ? -1 : stk.top();
//             stk.push(arr[i]);
//         }
//         return NGL;
//     }

// quick revision notes for Next Greater Element with example:
// 1. The problem involves finding the next greater element for each element in an array.
// 2. The next greater element for an element x is the first greater element on the left side of x in the array.
// 3. If no greater element exists, the next greater element is -1.
// 4. The approach uses a stack to keep track of elements and their next greater elements.
// 5. The time complexity is O(n) where n is the length of the array
// For the array [4, 5, 2, 10, 8],
// the next greater elements are [-1, -1, 5, -1, 10].
// Note: The example in the comments is illustrative; adjust it based on the actual input array