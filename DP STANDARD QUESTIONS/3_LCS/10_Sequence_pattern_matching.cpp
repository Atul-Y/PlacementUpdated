#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	// base case of recursion --> for initialization of dp - matrix
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m];
}

bool SeqPatternMatching(string X, string Y, int n, int m) {
	int lcs_len = LCS(X, Y, n, m);
	return lcs_len == n; // if length of LCS is equal to length of X then X is a subsequence of Y
}

signed main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	SeqPatternMatching(X, Y, n, m) ? "YES\n" : "NO\n";
	return 0;
}

// Quick Revision Notes for Sequence Pattern Matching with example:
// 1. Sequence Pattern Matching checks if one string is a subsequence of another.
// 2. A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.
// 3. The approach uses the Longest Common Subsequence (LCS) algorithm to determine if the first string is a subsequence of the second.
// 4. If the length of the LCS is equal to the length of the first string, it means the first string is a subsequence of the second.
// 5. The time complexity is O(n * m) where n and m are the lengths of the two strings.
// 6. Example: For strings "abc" and "ahbgdc", the LCS is "abc", which has a length of 3, equal to the length of "abc". Thus, "abc" is a subsequence of "ahbgdc".
// 7. If the first string is not a subsequence, the function returns false.