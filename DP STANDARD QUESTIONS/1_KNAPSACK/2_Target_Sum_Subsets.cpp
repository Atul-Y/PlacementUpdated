// Given an array of n integers (non-negative), and a target value tar, you need to check whether a subset of the array whose sum of elements is equal to the target tar exists or not.
// Please recall that a subset (or subsequence) of an array is taking zero or more elements from the array (in the same order in which they occur in the array).
// Here, you need to just print true or false whether such a target sum subset exists or not. You do not need to print the subset.


//======================================================================
//Bottom-Up Tabulation 
//======================================================================
#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum) {
    bool dp[n + 1][sum + 1];

    // Initialize the matrix
    for (int i = 0; i <= n; i++)
        dp[i][0] = true; // Sum 0 is always possible with empty subset

    for (int j = 1; j <= sum; j++)
        dp[0][j] = false; // Can't make positive sum with no elements

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) { 
                // include it or exclude it
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            } else {
                // can't include it, exclude only
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum]; // Final answer
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isSubsetSum(arr, n, sum))
        cout << "True";
    else
        cout << "False";

    return 0;
}

//======================================================================
//Recursive + Memoization -Top-Down
//======================================================================
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000; // assume max sum and n are < 1000
int dp[MAX][MAX]; // dp[n][sum] = -1 (uncomputed), 0 (false), 1 (true)

bool isSubsetSumUtil(int arr[], int n, int sum) {
    // Base cases
    if (sum == 0) return true;
    if (n == 0) return false;

    // Check memo table
    if (dp[n][sum] != -1)
        return dp[n][sum];

    if (arr[n - 1] <= sum) {
        // include or exclude
        dp[n][sum] = isSubsetSumUtil(arr, n - 1, sum - arr[n - 1]) ||
                     isSubsetSumUtil(arr, n - 1, sum);
    } else {
        // exclude
        dp[n][sum] = isSubsetSumUtil(arr, n - 1, sum);
    }

    return dp[n][sum];
}

bool isSubsetSum(int arr[], int n, int sum) {
    // Initialize dp with -1
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= sum; j++)
            dp[i][j] = -1;

    return isSubsetSumUtil(arr, n, sum);
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isSubsetSum(arr, n, sum))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}



//=======================================================================
//1️⃣ Recursive Approach (Without Memoization)
//=======================================================================
#include <iostream>
using namespace std;
bool isSubsetSum(int arr[], int n, int sum) {
    if (sum == 0) return true; // empty subset
    if (n == 0) return false; // no elements left

    if (arr[n - 1] > sum) {
        return isSubsetSum(arr, n - 1, sum); // skip current element
    } else {
        return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]); // include or skip current element
    }
}

int main() {
    int n;
    cin >> n; // number of elements
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // input array elements
    }
    int sum;
    cin >> sum; // target sum

    if (isSubsetSum(arr, n, sum)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}


/*
Tree diagram for isSubsetSum(arr, n, sum):

Each node represents a function call isSubsetSum(arr, n, sum).
At each step, we have two choices:
1. Exclude the current element: isSubsetSum(arr, n-1, sum)
2. Include the current element (if arr[n-1] <= sum): isSubsetSum(arr, n-1, sum-arr[n-1])

Example: arr = [3, 2, 7], sum = 7

isSubsetSum([3,2,7], 3, 7)
├── Exclude 7: isSubsetSum([3,2,7], 2, 7)
│   ├── Exclude 2: isSubsetSum([3,2,7], 1, 7)
│   │   ├── Exclude 3: isSubsetSum([3,2,7], 0, 7) => false
│   │   └── Include 3: isSubsetSum([3,2,7], 0, 4) => false
│   └── Include 2: isSubsetSum([3,2,7], 1, 5)
│       ├── Exclude 3: isSubsetSum([3,2,7], 0, 5) => false
│       └── Include 3: isSubsetSum([3,2,7], 0, 2) => false
└── Include 7: isSubsetSum([3,2,7], 2, 0) => true

If any path reaches sum == 0, return true.
*/





