#include <iostream>
using namespace std;

int main()
{
    string s="geeksforgeeks";
    int flag=0;
    int n=s.length();
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(s[j+1]<s[j])
            {
                swap(s[j+1],s[j]);
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
    cout<<s;
    return 0;
}