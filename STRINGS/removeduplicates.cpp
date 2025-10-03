#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// int main()
// {
//     string s="geeksforgeeks";
//     string res="";
//     unordered_map<char,int > ump;
//     for(int i=0;i<s.length();i++)
//     {
//         ump[s[i]]++;  // Count frequency of each character
//     }
//     for(auto i:ump)
//     {
//         if(i.second==0)
//         {
//             continue;
//         }
//         else if(i.second>=1) // If frequency is greater than or equal to 1, append to result
//         {
//             res=res+i.first;
//             i.second=0;           // Reset frequency to 0 to avoid duplicates in result
//         }
//     }
//     cout<<res;
//     return 0;
// }
#define SIZE 26 
int main()
{
    string s="AAABDCCEEFF";
    string res="";
    int freq[SIZE]={0};
    for(int i=0;i<s.length();i++)
    {
        freq[s[i]]++;
    }
    for(int i=0;i<s.length();i++)
    {
        if(freq[s[i]]>=1)
        {
            res=res+s[i];
            freq[s[i]]=0;
        }
    }
    cout<<res;
    return 0;
}