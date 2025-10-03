// Given an array arr[], the task is to check if it can be partitioned into two parts such that the sum of elements in both parts is the same.
// Note: Each element is present in either the first subset or the second subset, but not in both.

// Examples: 

// Input: arr[] = [1, 5, 11, 5]
// Output: true 
// Explanation: The array can be partitioned as [1, 5, 5] and [11]

// Input: arr[] = [1, 5, 3]
// Output: false
// Explanation: The array cannot be partitioned into equal sum sets.



//=======================================================================
// 1️⃣ Recursive Approach (Top-Down without memoization)
//=======================================================================
#include <iostream>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum) {
    // Base Cases
    if (sum == 0) return true;
    if (n == 0) return false;

    if (arr[n - 1] <= sum) {
        // include or exclude
        return isSubsetSum(arr, n - 1, sum - arr[n - 1]) || 
               isSubsetSum(arr, n - 1, sum);
    } else {
        // exclude only
        return isSubsetSum(arr, n - 1, sum);
    }
}

bool canPartition(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];

    if (total % 2 != 0)
        return false; // Can't split odd sum equally

    return isSubsetSum(arr, n, total / 2);
}

int main() {
    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << (canPartition(arr, n) ? "True" : "False") << endl;
    return 0;
}
//======================================================================
//2️⃣ Memoized Recursive Approach (Top-Down + DP)
//======================================================================
#include <iostream>
using namespace std;

const int MAX = 1000;
int dp[MAX][MAX];

bool isSubsetSumMemo(int arr[], int n, int sum) {
    if (sum == 0) return true;
    if (n == 0) return false;

    if (dp[n][sum] != -1)
        return dp[n][sum];

    if (arr[n - 1] <= sum)
        dp[n][sum] = isSubsetSumMemo(arr, n - 1, sum - arr[n - 1]) || 
                     isSubsetSumMemo(arr, n - 1, sum);
    else
        dp[n][sum] = isSubsetSumMemo(arr, n - 1, sum);

    return dp[n][sum];
}

bool canPartition(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];

    if (total % 2 != 0)
        return false;

    int sum = total / 2;

    // Initialize dp matrix
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= sum; j++)
            dp[i][j] = -1;

    return isSubsetSumMemo(arr, n, sum);
}

int main() {
    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << (canPartition(arr, n) ? "True" : "False") << endl;
    return 0;
}
//======================================================================
//3️⃣ Bottom-Up Tabulation Approach
//======================================================================
#include <iostream>
using namespace std;

bool canPartition(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];

    if (total % 2 != 0)
        return false;

    int sum = total / 2;

    bool dp[n + 1][sum + 1];

    // Initialize
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int j = 1; j <= sum; j++)
        dp[0][j] = false;

    // Fill DP Table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int main() {
    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << (canPartition(arr, n) ? "True" : "False") << endl;
    return 0;
}


// | Approach             | Time Complexity | Space Complexity |
// | -------------------- | --------------- | ---------------- |
// | Recursive            | Exponential     | O(n) stack       |
// | Memoized Top-Down    | O(n \* sum)     | O(n \* sum)      |
// | Bottom-Up Tabulation | O(n \* sum)     | O(n \* sum)      |
