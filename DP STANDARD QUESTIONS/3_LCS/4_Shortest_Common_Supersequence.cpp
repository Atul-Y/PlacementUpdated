

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

int SCS(string X, string Y, int n, int m) {
	return m + n - LCS(X, Y, n, m); // formula // SCS = length of X + length of Y - LCS(X, Y)
	// this is because the common characters in both strings are counted twice in the sum of their lengths.
	// So, we subtract the length of the LCS to get the length of the SCS.
	// The SCS is the shortest sequence that contains both strings as subsequences.
}

int main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	cout << SCS(X, Y, n, m) << endl;
	return 0;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

//printing the Shortest Common Supersequence is not required in this problem, but if needed, it can be done by backtracking through the LCS table.

#include <bits/stdc++.h>
using namespace std;

// Function to print the Shortest Common Supersequence
string printSCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1];

	// Fill dp table for LCS
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (X[i - 1] == Y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

	// Backtrack to build SCS
	int i = n, j = m;
	string scs;
	while (i > 0 && j > 0) {
		if (X[i - 1] == Y[j - 1]) {
			scs += X[i - 1];
			i--; j--;
		} else if (dp[i - 1][j] > dp[i][j - 1]) {
			scs += X[i - 1];
			i--;
		} else {
			scs += Y[j - 1];
			j--;
		}
	}
	while (i > 0) {
		scs += X[i - 1];
		i--;
	}
	while (j > 0) {
		scs += Y[j - 1];
		j--;
	}
	reverse(scs.begin(), scs.end());
	return scs;
}


int main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	cout << printSCS(X, Y, n, m) << endl; // calling the SCS function to get the length of the Shortest Common Supersequence
	return 0;
}

// Quick Revision Notes for Shortest Common Supersequence (SCS) with example:
// 1. The Shortest Common Supersequence (SCS) of two strings is the shortest string that has both strings as subsequences.
// 2. The SCS can be found using the formula: SCS = length of X + length of Y - LCS(X, Y), where LCS is the length of the Longest Common Subsequence.
// 3. The time complexity of finding the SCS is O(n * m), where n and m are the lengths of the two strings.
// 4. Example: For strings "AGGTAB" and "GXTXAYB", the LCS is "GTAB" with length 4.
//    The lengths of the strings are 6 and 7, respectively. Thus, the SCS length is 6 + 7 - 4 = 9.
// 5. The SCS can be constructed by backtracking through the LCS table,
//    ensuring that characters from both strings are included in the final result.
// 6. The SCS is not unique; there can be multiple valid SCS for the same pair of strings.
