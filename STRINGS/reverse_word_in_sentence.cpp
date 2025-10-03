     #include <bits/stdc++.h>
using namespace std;

int main()
{
    string s="we have worked a lot today";
    stack<string> st;
    for(int i=0;i<s.length();i++)
    {
        string word="";
        while(s[i]!=' ' && s[i]<s.length())
        {
            word=word+s[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}
// int main()
// {
//     string s="hello world";
//     int n=s.length();
//     string res;
//     int i=0;
//     while(i<n)
//     {
//         while(i<n && s[i]==' ')
//         {
//             i++;
//         }
//         if(i>=n)
//         {
//             break;
//         }
//         int j=i+1;
//         while(j<n && s[j]!=' ')
//         {
//             j++;
//         }
//         string sub=s.substr(i,j-i);
//         if(res.length()==0)
//         {
//             res=sub;
//         }
//         else 
//         {
//             res=sub + " " + res;
//         }
//         i=j+1;
//     }
//     cout<<res;
// }