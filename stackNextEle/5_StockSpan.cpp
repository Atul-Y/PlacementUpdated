#include <bits/stdc++.h>
using namespace std;
//brute force approach
// vector<int> StockSpan(vector<int>& arr) {
//     vector<int> result;
//     int n = arr.size();
//     for(int i = 0; i < n; i++) {
//         int span = 1; // Initialize span for the current day
//         for(int j = i - 1; j >= 0 && arr[j] <= arr[i]; j--) {
//             span++; // Increment span for each previous day with a lower price   
//         }
//         result.push_back(span); // Store the span for the current day
//     }
//     return result;
// }

vector<int> StockSpan(vector<int>& arr) {
    stack<int> s;
    int n = arr.size();
    vector<int> result(n);
    
    for(int i = 0; i < n; i++) {
        while(!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        result[i]= s.empty() ? (i + 1) : (i - s.top()); //agar stack empty hai to pura span hoga i+1 else i - s.top()
        s.push(i); // Push current index onto the stack
    }
    
    return result;
}

// quick revision notes for Stock Span Problem with example:
//this is based on next greatest element to left
// 1. sabse pehle next greatest element to left nikalna hai
// 2. left[i] mein NSL ka index store karna hai with empty case -1
// 3. fir span nikalna hai har index ke liye using formula: NSL[i] == -1 ? i+1 : (i - s.top())  //this is the span result 
// 4. span return karna hai
int main() {
    vector<int> arr = {10, 4, 5, 90, 120, 80};
    vector<int> result = StockSpan(arr);
    for(int i : result) {
        cout << i << " ";  // Output: 1 1 2 4 5 1
    }
    return 0;
}



