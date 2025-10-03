#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "ABCD";
    string p = "ACBD";
    if (s.length() != p.length())
    {
        cout << "not anagram";
    }
    else
    {
        sort(s.begin(), s.end());
        sort(p.begin(), p.end());

        int flag = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != p[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "anagram";
        }
        else
        {
            cout << "not anagram";
        }
    }
    return 0;
}


//best approach
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool areAnagrams(string &s1, string &s2) {
    
    if(s1.size() != s2.size()){
        return false;
    }
    
    // Create a hashmap to store
    // character frequencies
    unordered_map<char, int> charCount;
    
    // Count frequency of each
    // character in string s1
    for(char ch: s1) 
    	charCount[ch] += 1; //or charCount[[ch]]++;
  
    // Count frequency of each 
    // character in string s2
    for(char ch: s2) 
    	charCount[ch] -= 1; //or charCount[[ch]]--;
  
    // Check if all frequencies are zero
    for (auto& pair : charCount) {
        if (pair.second != 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    
    string s1 = "geeks";
    string s2 = "kseeg";
    
	if(areAnagrams(s1, s2)){
	    cout << "true";
	} 
	else{
	    cout << "false";
	}
	
    return 0;
}