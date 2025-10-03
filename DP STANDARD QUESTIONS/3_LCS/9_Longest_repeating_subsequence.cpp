#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1] && i != j) // just add an condition that element at ith index should not be equal to jth index 
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m];
}

signed main() {
	string X; cin >> X;
	int n = X.length();

	cout << LCS(X, X, n, n) << endl;
	return 0;
}

//provide quick short revision notes 
// for Longest Repeating Subsequence
// 1. It is a variation of LCS problem where we find the longest subsequence 
//    that appears more than once in the same string.
// 2. The key difference is that we cannot use the same character from the string
//    at the same index in both subsequences.
// 3. The approach is similar to LCS, but we add a condition to ensure
//    that characters at the same index are not considered.
// 4. The time complexity is O(n^2) and space complexity is O(n^2) for the DP approach.
// 5. The solution can be implemented using a 2D DP array where dp[i][j]
//    represents the length of the longest repeating subsequence for the first i characters of X and
//    the first j characters of Y, with the additional condition that i != j.
// 6. The final answer is found in dp[n][n] where n is the length of the string X.
 // for example, for the string "AABEBCDD", the longest repeating subsequence is "ABD" with length 3.
// 7. The algorithm iterates through the string, checking for matches and updating the DP