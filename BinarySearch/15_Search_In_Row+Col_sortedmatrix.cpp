//we need to find a element in a row and column wise sorted matrix
//eg: 1 3 5
//    2 4 7
//    6 8 9
//we can start from top right corner or bottom left corner
//if we start from top right corner then if the element is greater than the target then we can move left
//else we can move down
//if we start from bottom left corner then if the element is greater than the target then we can move up
//else we can move right

#include <bits/stdc++.h>
using namespace std;
bool searchInMatrix(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false; // Empty matrix
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    int row = 0, col = cols - 1; // Start from top-right corner

    while (row < rows && col >= 0) {
        if (matrix[row][col] == target) {
            return true; // Target found
        } else if (matrix[row][col] > target) {
            col--; // Move left
        } else {
            row++; // Move down
        }
    }

    return false; // Target not found
}