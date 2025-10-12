#include <iostream>
#include <vector>

using namespace std;



int minCost(int n, int m, vector<vector<int>>& arr, vector<vector<int>>& dp ) {

  // write your code here
  for (int r = n - 1; r >= 0; r--) {
    for (int c = m - 1; c >= 0; c--) {
      if (r == n - 1 && c == m - 1) {  //matlab hum apne last cell pr hain
        dp[r][c] = arr[r][c];
      }
      else if (r == n - 1) {  //matlab hum apne last row pr hain
        dp[r][c] = dp[r][c + 1] + arr[r][c];  //sirf right se a paenge
      }
      else if (c == m - 1) {  //matlab hum apne last column pr hain
        dp[r][c] = dp[r + 1][c] + arr[r][c];  //sirf down se a paenge
      }
      else {
        dp[r][c] = min(dp[r + 1][c], dp[r][c + 1]) + arr[r][c];
      }
    }
  }

  return dp[0][0];
                                                                            
}

//OR

// loop from 0,0 to n-1,m-1
int minCost(int n, int m, vector<vector<int>>& arr, vector<vector<int>>& dp ) {

  // write your code here
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      if (r == 0 && c == 0) {  //matlab hum apne first cell pr hain
        dp[r][c] = arr[r][c];
      }
      else if (r == 0) {  //matlab hum apne first row pr hain
        dp[r][c] = dp[r][c - 1] + arr[r][c];  //sirf left se aa paenge
      }
      else if (c == 0) {  //matlab hum apne first column pr hain
        dp[r][c] = dp[r - 1][c] + arr[r][c];  //sirf up se aa paenge
      }
      else {
        dp[r][c] = min(dp[r - 1][c], dp[r][c - 1]) + arr[r][c];
      }
    }
  }

  return dp[n - 1][m - 1];
                                                                            
}


int main()  {

  int n;
  int m;

  cin >> n >> m;

  vector<vector<int>> arr(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int>(m));    //for this see gfg  2d vectors in c++ with user defined size

  cout << minCost(n, m, arr, dp);
}


// 6
// 6
// 0 1 4 2 8 2
// 4 3 6 5 0 4
// 1 2 4 1 4 6
// 2 0 7 3 2 2
// 3 1 5 9 2 4
// 2 7 0 8 5 1