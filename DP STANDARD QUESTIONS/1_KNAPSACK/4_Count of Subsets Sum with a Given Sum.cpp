// Given an array arr[] of length n and an integer target, the task is to find the number of subsets with a sum equal to target.

// Examples: 

// Input: arr[] = [1, 2, 3, 3], target = 6 
// Output: 3 
// Explanation: All the possible subsets are [1, 2, 3], [1, 2, 3] and [3, 3]

// Input: arr[] = [1, 1, 1, 1], target = 1 
// Output: 4 
// Explanation: All the possible subsets are [1], [1], [1] and [1]


//=======================================================================
//1️⃣ Recursive Approach (Without Memoization)
//=======================================================================
// #include <iostream>
// using namespace std;

// int countSubsets(int arr[], int n, int target) {
//     // Base Cases
//     if (target == 0) return 1;  // one subset (empty set)
//     if (n == 0) return 0;

//     if (arr[n - 1] <= target) {
//         // include + exclude
//         return countSubsets(arr, n - 1, target - arr[n - 1]) +
//                countSubsets(arr, n - 1, target);
//     } else {
//         // can't include
//         return countSubsets(arr, n - 1, target);
//     }
// }

// int main() {
//     int arr[] = {1, 2, 3, 3};
//     int target = 6;
//     int n = sizeof(arr) / sizeof(arr[0]);

//     cout << countSubsets(arr, n, target) << endl;
//     return 0;
// }
//=======================================================================
// 2️⃣ Recursive + Memoization (Top-Down DP)
//=======================================================================
// #include <iostream>
// #include <cstring>
// using namespace std;

// const int MAX = 1000;
// int dp[MAX][MAX];

// int countSubsetsMemo(int arr[], int n, int target) {
//     if (target == 0) return 1;
//     if (n == 0) return 0;

//     if (dp[n][target] != -1)
//         return dp[n][target];

//     if (arr[n - 1] <= target) {
//         dp[n][target] = countSubsetsMemo(arr, n - 1, target - arr[n - 1]) +
//                         countSubsetsMemo(arr, n - 1, target);
//     } else {
//         dp[n][target] = countSubsetsMemo(arr, n - 1, target);
//     }

//     return dp[n][target];
// }

// int main() {
//     int arr[] = {1, 2, 3, 3};
//     int target = 6;
//     int n = sizeof(arr) / sizeof(arr[0]);

//     memset(dp, -1, sizeof(dp));
//     cout << countSubsetsMemo(arr, n, target) << endl;
//     return 0;
// }
//=======================================================================
// 3️⃣ Bottom-Up Tabulation (Iterative DP)
//=======================================================================

#include <iostream>
using namespace std;

int countSubsets(int arr[], int n, int target) {
    int dp[n + 1][target + 1];

    // Initialize
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1; 

    for (int j = 1; j <= target; j++)  
        dp[0][j] = 0; 

    // Fill dp table    
    for (int i = 1; i <= n; i++) {
        
        for (int j = 1; j <= target; j++) {  

            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][target];
}

int main() {
    int arr[] = {1, 2, 3, 3};
    int target = 6;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << countSubsets(arr, n, target) << endl;  // Output: 3
    return 0;
}


// | `i↓ / j→` |  0 |  1 |  2 |  3 |  4 |  5 |  6 |
// | --------: | -: | -: | -: | -: | -: | -: | -: |
// |         0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |
// |     1 (1) |  1 |  1 |  0 |  0 |  0 |  0 |  0 |
// |     2 (2) |  1 |  1 |  1 |  1 |  0 |  0 |  0 |
// |     3 (3) |  1 |  1 |  1 |  2 |  1 |  1 |  1 |
// |     4 (3) |  1 |  1 |  1 |  3 |  2 |  2 |  3 |


//                        f(4,6)
//                       /         \
//           include arr[3]=3       exclude arr[3]
//                /                       \
//            f(3,3)                      f(3,6)
//           /     \                     /        \
// include arr[2]=3  exclude         include        exclude
//      /             \                 \                 \
//   f(2,0)         f(2,3)            f(2,3)              f(2,6)
//     |           /     \            /     \              /      \
//   [✓]     f(1,1)    f(1,3)      f(1,1)  f(1,3)       f(1,4)      f(1,6)
//            / \       / \         / \     / \           /  \          / \
//      f(0,0) f(0,2) f(0,3)     f(0,0) f(0,2) f(0,3)  f(0,3) f(0,4) (0,5) (0,6) 
//        ✓     ✗       ✗      ✓     ✗     ✗     ✗      ✗
