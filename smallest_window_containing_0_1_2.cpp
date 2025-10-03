#include <iostream>
#include <string>
#include <climits>
using namespace std;

#include <iostream>
#include <string>
#include <climits>
using namespace std;

int findSmallestSubstringWith012(const string& str) {
    int n = str.size();
    int i = 0, j = 0; // i = window start, j = window end
    int minLength = INT_MAX;
    int count[3] = {0, 0, 0}; // Count of '0', '1', and '2'

    while (j < n) {
        // Add current character at j to the window
        count[str[j] - '0']++;

        // Try to shrink the window when it contains all three characters
        while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
            // Calculate window length and update minimum
            int windowLength = j - i + 1;
            minLength = min(minLength, windowLength);

            // Shrink window from the start
            count[str[i] - '0']--;
            i++;
        }

        // Move the end of the window forward
        j++;
    }

    return (minLength == INT_MAX) ? -1 : minLength;
}

int main() {
    string input1 = "011112";
    string input2 = "12121";

    cout << "Smallest length for '011112': " << findSmallestSubstringWith012(input1) << endl;
    cout << "Smallest length for '12121': " << findSmallestSubstringWith012(input2) << endl;

    return 0;
}

// Pseudo Code for Smallest Window Containing 0, 1, and 2
/* function findSmallestSubstringWith012(str):
    n = length of str
    i = 0, j = 0 // window start and end
    minLength = infinity
    count[3] = {0, 0, 0} // Count of '0', '1', and '2'

    while j < n:
        count[str[j] - '0']++ // Add current character to the window

        while count[0] > 0 and count[1] > 0 and count[2] > 0:
            windowLength = j - i + 1
            minLength = min(minLength, windowLength) // Update minimum length

            count[str[i] - '0']-- // Shrink window from the start
            i++

        j++ // Move the end of the window forward

    return minLength if minLength != infinity else -1
*/