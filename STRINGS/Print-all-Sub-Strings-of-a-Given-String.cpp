#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string s = "abcd";
    // subString(s, s.length());
    int n = s.length(); // 4
    
    // Logic to print all substring
    // using substr()
    for (int i = 0; i < n; i++)
        for (int len = 1; len <= n - i; len++)
            cout << s.substr(i, len) << endl;
    return 0;
}

// Output:
// a
// ab
// abc
// abcd
// b
// bc
// bcd
// c
// cd
// d