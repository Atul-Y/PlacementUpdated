
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "MCMXCIV";
    int n = str.size();

    unordered_map<char, int> um;

    um['I'] = 1;
    um['V'] = 5;
    um['X'] = 10;
    um['L'] = 50;
    um['C'] = 100;
    um['D'] = 500;
    um['M'] = 1000;

    int result = um[str[n - 1]];

    for (int j = n - 2; j >= 0; j--)
    {
        if (um[str[j]] < um[str[j + 1]])
            result = result - um[str[j]];

        else
            result = result + um[str[j]];
    }

    cout << result;
}