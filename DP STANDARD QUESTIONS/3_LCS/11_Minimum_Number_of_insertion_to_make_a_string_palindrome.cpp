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

int LPS(string X, int n) {
	string rev_X = X;
	reverse(rev_X.begin(), rev_X.end());
	return LCS(X, rev_X, n, n); // LPS is the LCS of the string and its reverse
}

int MinInsertForPallindrome(string X, int n) {
	return n - LPS(X, n); // substract LPS from the length of string to get Minimum number of insertion to make a string palindrome
}

int main() {
	string X; cin >> X;
	int n = X.length();

	cout << MinInsertForPallindrome(X, n) << endl;
	return 0;
}

// quick revision notes for Minimum Insertion to Make a String Palindrome with example:
// 1. The problem involves converting a string into a palindrome by inserting the minimum number of characters.
// 2. A palindrome reads the same forwards and backwards.
// 3. The approach uses the Longest Palindromic Subsequence (LPS) to find the longest subsequence that is a palindrome.
// 4. The length of the LPS gives the number of characters that are already in the correct order to form a palindrome.
// 5. The minimum number of insertions required to make the string a palindrome is calculated as the difference between 
//    the length of the string and the length of the LPS.
// 6. The time complexity is O(n^2) where n is the length of the string.
// For the string "abc", the longest palindromic subsequence (LPS) is any single character: "a", "b", or "c", so LPS length is 1.
// 7. Therefore, the minimum number of insertions is 2 like inserting "b" and "c" to make it "abcba" or "acbca" or "bacab", etc.
//But the algorithm doesn’t bother how you insert — it only ensures the count of insertions is minimized.
// For example, inserting "b" and "a" in "abc" results in "abcba", which is a palindrome
// Similarly, inserting "a" and "c" results in "acbca", which is also a palindrome.
// Thus, the minimum number of insertions to make "abc" a palindrome is 2.