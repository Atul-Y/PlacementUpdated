#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n=arr.size();
        vector<int> res;
        
        for(int i=0;i<=n-k;i++){
              bool flag=false;
            for(int j=i;j<i+k;j++){
                if(arr[j]<0){
                    res.push_back(arr[j]);
                    flag=true;
                    break;
                }
            }
                if(flag==false){
                    res.push_back(0);
                }
        }
        return res;
    }
};

//optimized solution using deque
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> printFirstNegativeInteger(vector<int>& arr, int k) {
        deque<int> dq;  // stores indices of negative numbers
        vector<int> result;

        int i = 0, j = 0;
        int n = arr.size();

        while (j < n) {
            // Step 1: If current element is negative, add its index to the deque
            if (arr[j] < 0) {
                dq.push_back(j);
            }

            // Step 2: If we haven't reached window size yet, just move j
            if (j - i + 1 < k) {
                j++;
            }
            // Step 3: When window size hits k
            else if (j - i + 1 == k) {
                // If deque is not empty, the front holds the first negative number's index
                if (!dq.empty()) {
                    result.push_back(arr[dq.front()]);
                } else {
                    result.push_back(0);  // No negative number in the window
                }

                // Step 4: Before sliding the window, remove the index if it is going out of the window
                if (!dq.empty() && dq.front() == i) {
                    dq.pop_front();
                }

                // Slide the window
                i++;
                j++;
            }
        }

        return result;
    }
};
