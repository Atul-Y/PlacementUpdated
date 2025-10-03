#include <bits/stdc++.h>
using namespace std;

int LCSubstr(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

  // base condition 
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0; //

  // choice diagram 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when both string's last char is same
				dp[i][j] = 1 + dp[i - 1][j - 1]; // count the number and decrement the table 
			else
				dp[i][j] = 0; // variation from LCS(DP)

	int mx = INT_MIN;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			mx = max(mx, dp[i][j]);

	return mx;
}

int main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	cout << LCSubstr(X, Y, n, m) << endl;
	return 0;
}


// Recursive way: Returns length of longest common substring ending at X[n-1] and Y[m-1]
int LCSubstrRec(string X, string Y, int n, int m, int count) {
	if (n == 0 || m == 0)
		return count;
	int cnt = count;
	if (X[n - 1] == Y[m - 1])
		cnt = LCSubstrRec(X, Y, n - 1, m - 1, count + 1);
	int cnt1 = LCSubstrRec(X, Y, n, m - 1, 0);
	int cnt2 = LCSubstrRec(X, Y, n - 1, m, 0);
	return max(cnt, max(cnt1, cnt2));
}

int LCSubstrRecursive(string X, string Y) {
	int n = X.length(), m = Y.length();
	return LCSubstrRec(X, Y, n, m, 0);
}
int main() {
	string X, Y; cin >> X >> Y;
	cout << LCSubstrRecursive(X, Y) << endl;
	return 0;
}

//LCSubstrMemoization
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int LCSubstrMemo(string X, string Y, int n, int m, int count) {
	if (n == 0 || m == 0)
		return count;

	if (dp[n][m] != -1)
		return dp[n][m];

	int cnt = count;
	if (X[n - 1] == Y[m - 1])
		cnt = LCSubstrMemo(X, Y, n - 1, m - 1, count + 1);
	int cnt1 = LCSubstrMemo(X, Y, n, m - 1, 0);
	int cnt2 = LCSubstrMemo(X, Y, n - 1, m, 0);

	return dp[n][m] = max(cnt, max(cnt1, cnt2));
}


