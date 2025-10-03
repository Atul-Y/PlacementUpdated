#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// int main()
// {
//     string s="geeksforgeeks";
//     unordered_map<char,int> ump;
//     for(char i=0;i<s.length();i++)
//     {
//         ump[s[i]]++;
//     }
//     for(auto i: ump)
//     {
//         cout<<i.first<<" "<<i.second<<endl;
//     }
// }

#define SIZE 26
int main()
{
    string s ="geeksforgeeks";
    int freq[SIZE]={0};
    for(int i=0;i<s.length();i++)
    {
        freq[s[i]-'a']++;
    }
    for(int i=0;i<s.length();i++)
    {
        if(freq[s[i]-'a']!=0)
        {
            cout<<s[i]<<" "<<freq[s[i]-'a']<<endl;
            freq[s[i]-'a']=0;
        }
       
    }

    return 0;
}