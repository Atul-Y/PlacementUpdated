

// Input:  W = 4, profit[] = [1, 2, 3], weight[] = [4, 5, 1]
// Output: 3

#include <iostream>
#include <vector>
using namespace std;

void zeroOneKnapsack(int n, vector<int> val, vector<int> weight, int cap) {

  vector<vector<int>> dp(n + 1, vector<int>(cap + 1));

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < cap + 1; j++) {
      if (j >=weight[i-1]) {
        int rcap=j-weight[i-1];
        dp[i][j] =  max(dp[i-1][rcap]+val[i-1],dp[i-1][j]);
      }
      else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  cout << dp[n][cap];
}

int main() {

  int n;
  cin >> n;

  vector<int> val(n);
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }

  vector<int> weight(n);
  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }

  int cap;
  cin >> cap;

  zeroOneKnapsack(n, val, weight, cap);


}

//ADITYA VERMA CODE

//======================================================================
//RECURSIVE SOLUTION
//======================================================================
#include <iostream>
using namespace std;

int Knapsack(int wt[], int val[], int W, int n) {
	// every recursive solution will have a base condition 
  // for base condition we need to think of the smallest valid input that we can pass 
  // array size can be atleast 0 || min weight can be 0 but not negetive; 
	if (n == 0 || W == 0)
		return 0;

	// these are the choices we are having 
	if (wt[n - 1] <= W) {
		return max(val[n - 1] + Knapsack(wt, val, W - wt[n - 1], n - 1),
		           Knapsack(wt, val, W, n - 1));
	}
	else if (wt[n - 1] > W) // if the weight is greater then the required weight there is no sence for taking that value. 
		return Knapsack(wt, val, W, n - 1); // return as it is by redusing the size of array 
	else
		return -1; 
}

int main() {
	int n,W; 
  cin >> n; // number of items
	int val[n], wt[n]; // values and weights of array
	for (int i = 0; i < n; i++)
		cin >> wt[i];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	
  cin >> W; // Knapsack capacity

	cout << Knapsack(wt, val, W, n) << endl;
	return 0;
}
// T(N) = 2T(N-1) + O(1), which is simplified to O(2^N).



//======================================================================
// Knapsack Memoization-Top-Down
//==================================================================
#include <iostream>
using namespace std;

const int D = 1000; // DP - matrix dimension

int t[D][D]; // DP matrix

int Knapsack(int wt[], int val[], int W, int n) {
	// base case
	if (n == 0 || W == 0)
		return 0;

	// if already calculated use the value from the matrix
	// this is the memoization part of the code
	if (t[n][W] != -1)
		return t[n][W];
  
	// else calculate
	else {
		if (wt[n - 1] <= W)
			t[n][W] = max(val[n - 1] + Knapsack(wt, val, W - wt[n - 1], n - 1),Knapsack(wt, val, W, n - 1));
		else if (wt[n - 1] > W)
			t[n][W] = Knapsack(wt, val, W, n - 1);

		return t[n][W];
	}
}

signed main() {
	int n; cin >> n; // number of items
	int val[n], wt[n]; // values and wts array
	for (int i = 0; i < n; i++)
		cin >> wt[i];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	int W; cin >> W; // capacity

	// matrix initialization
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= W; j++)
			t[i][j] = -1; // initialize matrix with -1

	cout << Knapsack(wt, val, W, n) << endl;
	return 0;
}



//==============================================================================
// Knapsack Bottom-Up(DP)
//==============================================================================
#include <iostream>
using namespace std;

int Knapsack(int wt[], int val[], int W, int n) {
	int t[n + 1][W + 1]; // DP matrix

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= W; j++) {
			if (i == 0 || j == 0) // base case // filling 1st row and 1st column of the matrix with zero as per the base condition of the recursive solution 
				t[i][j] = 0;
			else if (wt[i - 1] <= j) { // current wt can fit in bag // this is for the choice diagram of the recursive solution
				int val1 = val[i - 1] + t[i - 1][j - wt[i - 1]]; // take current wt // and after taking weight substract the inserted weight from the final weight 
				int val2 = t[i - 1][j]; // skip current wt
				t[i][j] = max(val1, val2);
			}
			else if (wt[i - 1] > j) // current wt doesn't fit in bag
				t[i][j] = t[i - 1][j]; // move to next
		}
	}

	return t[n][W];
}

int main() {
	int n; cin >> n; // number of items
	int val[n], wt[n]; // values and wts array
	for (int i = 0; i < n; i++)
		cin >> wt[i];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	int W; cin >> W; // capacity

	cout << Knapsack(wt, val, W, n) << endl;
	return 0;
}

/* Complexity Analysis:
Time Complexity: O(N*W). 
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W). 
The use of 2-D array of size ‘N*W’.

Input:  W = 4, profit[] = [1, 2, 3], weight[] = [4, 5, 1]
Output: 3
table after the completion of the code:
	  0   1   2   3   4     --> Capacity(j)  
    -----------------  
   0| 0 | 0 | 0 | 0 | 0
   1| 0 | 0 | 0 | 0 | 1
   2| 0 | 0 | 0 | 0 | 1
   3| 0 | 3 | 3 | 3 | 3
   ^
   | 
   Number of items(i)

   remmeber the index of wt and val array starts from 0 but in the matrix it starts from 1 that's why we do i-1 and j-1 while accessing the array elements.
*/