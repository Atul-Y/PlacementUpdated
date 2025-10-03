#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    string str="gskkgfn1  msmg,nlvnljkfhksjglns";
    for(int i=0;i<str.length();i++){
        if(str[i]>='a' && str[i]<='z'){ // check if character is lower case
            str[i]=str[i]-32;   // convert to upper case
        }

    }
    cout<<str;

    for(int i=0;i<str.size();i++){
        if(str[i]>='A'  &&  str[i]<='Z'){ // check if character is upper case
            str[i]=str[i]+32; // convert to lower case
        }
    }
    cout<<endl;
    cout<<str;
    return 0;
}

// Why 32?
// In ASCII, the difference between uppercase and lowercase letters is always 32.

// ASCII value of 'a' is 97, 'A' is 65.
// The difference is 32.
// Subtracting 32 from a lowercase letter's ASCII value gives its uppercase equivalent.
// Example: 'g' (ASCII 103) → 103 - 32 = 71 → 'G'

// Adding 32 to an uppercase letter's ASCII value gives its lowercase equivalent.
// Example: 'G' (ASCII 71) → 71 + 32 = 103 → 'g'

// to know the ascii value of a character
// 'a' to 'z' = 97 to 122
// 'A' to 'Z' = 65 to 90    
// '0' to '9' = 48 to 57