#include <bits/stdc++.h>
using namespace std;
// Given an array arr[] of size n, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum. 
// Example: 

// Input: arr = [1, 6, 11, 5]
// Output: 1
// Explanation: S1 = [1, 5, 6], sum = 12,  S2 = [11], sum = 11,  Absolute Difference (12 - 11) = 1

// Input: arr = [1, 5, 11, 5]
// Output: 0
// Explanation: S1 = [1, 5, 5], sum = 11, S2 = [11], sum = 11, Absolute Difference (11 - 11) = 0 

// Approach:
// 1. Calculate the total sum of the array.
// 2. Use a subset sum approach to find the maximum sum that can be formed with half of the total sum.
//3. The minimum difference will be the absolute difference between twice the maximum subset sum and the total sum.

//=======================================================================
// 1️⃣ Recursive Approach (Without Memoization)
//=======================================================================
int solveRecursive(vector<int>& arr, int n, int sumCalculated, int totalSum) {
    if (n == 0)
        return abs((totalSum - sumCalculated) - sumCalculated); // abs(S2 - S1)  = abs((totalSum - sumCalculated) - sumCalculated) = abs(totalSum - 2 * sumCalculated); so we 

    // Include current element in subset1   ** //why not any condition here because we need to consider all the elements because we are here not bound by any condition like capacity of knapsack so we can include or exclude any element
    int include = solveRecursive(arr, n - 1, sumCalculated + arr[n - 1], totalSum);

    // Exclude current element from subset1
    int exclude = solveRecursive(arr, n - 1, sumCalculated, totalSum);

    return min(include, exclude);
}

int minSubsetDiffRecursive(vector<int>& arr) {
    int totalSum = 0;
    for (int x : arr) totalSum += x;
    return solveRecursive(arr, arr.size(), 0, totalSum);
}
//=======================================================================
// 2️⃣ Memoization (Top-Down DP)
//=======================================================================

int dp[101][10001]; // adjust size if needed

int solveMemo(vector<int>& arr, int n, int sumCalculated, int totalSum) {
    if (n == 0)
        return abs((totalSum - sumCalculated) - sumCalculated);

    if (dp[n][sumCalculated] != -1)
        return dp[n][sumCalculated];

    int include = solveMemo(arr, n - 1, sumCalculated + arr[n - 1], totalSum);
    int exclude = solveMemo(arr, n - 1, sumCalculated, totalSum);

    return dp[n][sumCalculated] = min(include, exclude);
}

int minSubsetDiffMemo(vector<int>& arr) {
    memset(dp, -1, sizeof(dp));
    int totalSum = 0;
    for (int x : arr) totalSum += x;
    return solveMemo(arr, arr.size(), 0, totalSum);
}
//=======================================================================
// 3️⃣ Bottom-Up DP
//=======================================================================

int minSubsetDiffTabulation(vector<int>& arr) {
    int n = arr.size();
    int totalSum = 0;
    for (int x : arr) totalSum += x;

    // dp[i][j] = true if subset with sum j is possible with first i elements
    vector<vector<bool>> dp(n + 1, vector<bool>(totalSum + 1, false));

    // Base case: sum = 0 is always possible
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;  // 1 way to make sum 0 (empty set)

    for (int j = 1; j <= totalSum; j++)
		dp[0][j] = false;    // No elements to form a positive sum

    // Fill table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= totalSum; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    // Find the minimum difference
    int minDiff = INT_MAX;
    for (int s1 = 0; s1 <= totalSum / 2; s1++) {
        if (dp[n][s1]) {
            int s2 = totalSum - s1;
            minDiff = min(minDiff, abs(s2 - s1));
        }
    }

    return minDiff;
}
int main() {
    vector<int> arr = {1, 6, 11, 5};

    // Using Recursive Approach
    cout << "Minimum Subset Sum Difference (Recursive): " << minSubsetDiffRecursive(arr) << endl;

    // Using Memoization Approach
    cout << "Minimum Subset Sum Difference (Memoization): " << minSubsetDiffMemo(arr) << endl;

    // Using Bottom-Up DP Approach
    cout << "Minimum Subset Sum Difference (Tabulation): " << minSubsetDiffTabulation(arr) << endl;

    return 0;
}

//Intuition:
// S1 + S2 = sum
// → Diff = |S1 - S2|
// → Diff = |S1 - (sum - S1)| = |2*S1 - sum|
// We need to find the subset with sum closest to sum/2
// This will minimize the difference between S1 and S2


//tree diagram// 1. Start with the entire array and a target sum of totalSum/2.
// 2. For each element, decide whether to include it in the subset or not.
// 3. If included, reduce the target sum by the element's value and move to the next element.
// 4. If not included, just move to the next element without changing the target sum    
// 5. If the target sum becomes zero, it means we found a valid subset.
// 6. If we reach the end of the array without achieving the target sum, backtrack to explore other possibilities.
// 7. The minimum difference is calculated as the absolute difference between twice the sum of the subset and the total sum of the array.
// 8. Repeat the process for all elements to find the minimum difference.



