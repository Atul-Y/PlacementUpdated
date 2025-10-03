//exapmple:
// X = "AGGTAB", Y = "GXTXAYB"
// Output: 4 // The longest common subsequence is "GTAB" which has length 4.

// recursive way------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m) {
	// base case
	if (n == 0 || m == 0)
		return 0;

  // choice diagram
	// when both string X and Y is having same last char
	if (X[n - 1] == Y[m - 1])
		return 1 + LCS(X, Y, n - 1, m - 1); // count the number and decreament the both's string length
	// when both string's last character is not same 
	else
		return max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1));// one take full and another by leaving last char and vice versa as per choice diagram
	// pick max of both the cases
}

int main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	cout << LCS(X, Y, n, m) << endl;
	return 0;
}


//  Longest Common Subsequence Top down (Memoization)

#include <bits/stdc++.h>
using namespace std;


int dp[1001][1001];

int LCS(string X, string Y, int n, int m) {
	// base case
	if (n == 0 || m == 0)
		dp[n][m] = 0;

	if (dp[n][m] != -1) // when table is not having -1 then return the value which is preseent in that block
		return dp[n][m];

  // choice diagram 
	// when last character is same
	if (X[n - 1] == Y[m - 1])
		dp[n][m] = 1 + LCS(X, Y, n - 1, m - 1);// count the number and decreament the both's string length // store the value in particular block 
	// when last character is not same -> pick max
	else
		dp[n][m] = max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1)); // one take full and another by leaving last char and vice versa // store the value in particular block 

	return dp[n][m];
}

int main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	memset(dp, -1, sizeof(dp)); // intialize the whole dp matrix with -1; // from memset we can initialise either -1 and zero;

	cout << LCS(X, Y, n, m) << endl;
	return 0;
}


//  Longest Common Subsequence Bottom Up(DP)


#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	// initialize 1st row and  of dp matrix with 0 according to the base condition of recursion // base case of recursion --> for initialization of dp - matrix
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;
// choise diagram is used to fill rest of the matrix 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when last character is same
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else // when last character is not same -> pick max
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m]; // last row and last column element will give the length of the LCS;
}

int main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	cout << LCS(X, Y, n, m) << endl;
	return 0;
}

// sumeet code using formula 

//  l(s1,s2)=l(r1,r2)+1  when c1==c2
//  l(s1,s2)=max(l(s1,r2),l(s2,r1))  when c1!=c2

// import java.io.*;
// import java.util.*;

// public class Main {

//     public static void main(String[] args) throws Exception {
//         Scanner scn=new Scanner(System.in);
//         String str1 = scn.nextLine();
//         String str2 = scn.nextLine();
        
//         int[][] dp = new int[str1.length() + 1][str2.length() + 1];
//         for(int i = dp.length - 2; i >= 0; i--){
//             for(int j = dp[0].length - 2; j >= 0; j--){
//                 if(str1.charAt(i) == str2.charAt(j)){
//                     dp[i][j] = 1 + dp[i + 1][j + 1];
//                 } else {
//                     dp[i][j] = Math.max(dp[i + 1][j], dp[i][j + 1]); 
//                 }
//             }
//         }
//         System.out.println(dp[0][0]);
//     }
// }


                        

