#include <bits/stdc++.h>
using namespace std;


int unioncount(int a[],int n,int b[],int m)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(a[i]);
    }
    for(int i=0;i<m;i++)
    {
        s.insert(b[i]);
    }
    return s.size();
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    cout<<unioncount(a,n,b,m);
}


//------------second approach-------------------


int doUnion(int a[], int n, int b[], int m)  {
        unordered_map<int, int> frequency;
        for(int i = 0;i<n;i++)
        {
            frequency[a[i]]++;
        }
        for(int i = 0;i<m;i++)
        {
            frequency[b[i]]++;
        }
        return frequency.size();
    }