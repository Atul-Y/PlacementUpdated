// Given a word pattern and a string text consisting of lowercase characters, the task is to return the count of substrings in text which are anagrams of the pattern.

// Examples:

// Input : text = "forxxorfxdofr", pattern = "for"
// Output : 3
// Explanation : Anagrams present are for, orf and ofr. Each appears in the text once and hence the count is 3.

// Input : text = "aabaabaa", pattern = "aaba"
// Output : 4
// Explanation : Anagrams present are aaba and abaa. Each appears twice in the text and hence the count is 4.

// brute force approach
//  1. Generate all substrings of the text.
//  2. For each substring, check if it is an anagram of the pattern.
//  3. Count the number of valid anagrams found.
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int countAnagrams(const string &text, const string &pattern)
{
    int count = 0;
    int patternLength = pattern.length();
    int textLength = text.length();

    // Create a frequency map for the pattern
    unordered_map<char, int> patternMap;
    for (char c : pattern)
    {
        patternMap[c]++;
    }

    // Iterate through all substrings of the text
    for (int i = 0; i <= textLength - patternLength; i++)
    {
        unordered_map<char, int> textMap;
        for (int j = 0; j < patternLength; j++)
        { // or j=i to j < i + patternLength then textMap[text[i + j]]++ to textMap[text[j]]++;
            textMap[text[i + j]]++;
        }

        // Check if the current substring is an anagram of the pattern
        if (textMap == patternMap)
        {
            count++;
        }
    }

    return count;
}

// optimized approach using sliding window technique
//  User function template for C++
int countAnagrams(string &pat, string &txt)
{
    // code here
    int count = 0;
    int k = pat.length();
    int n = txt.length();
    int i = 0, j = 0;
    unordered_map<char, int> textMap;
    unordered_map<char, int> patternMap;
    for (char c : pat)
    {
        patternMap[c]++;
    }

    while (j < n)
    {
        textMap[txt[j]]++;
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1)
        {
            if (textMap == patternMap)
            {
                count++;
            }
            textMap[txt[i]]--;
            if (textMap[txt[i]] == 0)
            {
                textMap.erase(txt[i]);
            }
            i++;
            j++;
        }
    }
    return count;
}