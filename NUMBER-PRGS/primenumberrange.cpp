#include <iostream>
using namespace std;
int primenumber(int n)
{
    // int flag=0;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return 0;
    }
    return 1;
}
int main()
{
    int l=2,u=20;
    for(int i=l;i<=u;i++)
    {
        if(primenumber(i))
        {
            cout<<i<<" ";
        }
    }
}