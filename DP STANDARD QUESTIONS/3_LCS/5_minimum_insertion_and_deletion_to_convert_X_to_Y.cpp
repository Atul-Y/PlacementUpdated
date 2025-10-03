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
			if (X[i - 1] == Y[j - 1]) // when last character is same
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else // when last character is not same -> pick max
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m];
}

void MinInsertDel(string X, string Y, int n, int m) {
	int lcs_len = LCS(X, Y, n, m);
	cout << "Minimum number of deletions = " << (n - lcs_len)<<endl;
  cout << "Minimum number of insertions = " << (m - lcs_len)<<endl;
}

int main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	MinInsertDel(X, Y, n, m);
    cout <<endl;
	return 0;
}
// quick revision notes for Minimum Insertion and Deletion to Convert X to Y with example:
// 1. The problem involves converting one string (X) into another (Y) using the minimum number of insertions and deletions.
// 2. The approach uses the Longest Common Subsequence (LCS) to find the common characters between the two strings.
// 3. The length of the LCS gives the number of characters that are already in the correct order in both strings.
// 4. The minimum number of deletions required to convert X to Y is calculated as the difference between the length of X and the length of the LCS.
// 5. The minimum number of insertions required to convert X to Y is calculated as the difference between the length of Y and the length of the LCS.
// 6. The time complexity is O(n * m) where n and m are the lengths of the two strings.
// 7. Example: For strings "abcde" and "ace", the LCS is "ace" with a length of 3.
//    Therefore, the minimum number of deletions is 2 (from "abcde") and the minimum number of insertions is 0 (since "ace" is already a subsequence of "abcde").