#include <bits/stdc++.h>
using namespace std;

string LCS(string X, string Y, int n, int m) {
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

		
				// this is the backtracking part of the code
	int i = n, j = m;
	string lcs = "";  
	while (i > 0 && j > 0) {
		if (X[i - 1] == Y[j - 1]) {
			lcs += X[i - 1]; // insert in string  // store the character in lcs string when both last characters are same
			i--, j--;
		}
		else {
			if (dp[i][j - 1] > dp[i - 1][j])
				j--; // move to the larger side  // if last character of Y is greater than X then move to left side
			else
				i--; // if last character of X is greater than Y then move to up side
		}
	}
	reverse(lcs.begin(), lcs.end()); // at last reverse the string to get LCS 

	return lcs;
}

signed main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	cout << LCS(X, Y, n, m) << endl;
	return 0;
}
