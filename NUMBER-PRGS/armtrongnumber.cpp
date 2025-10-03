#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int sum=0;
    int temp=n;
    while(n>0)
    {
        int rem=n%10;
        sum=sum+rem*rem*rem;
        n=n/10;
    }
    if(temp==sum)
    {
        cout<<"ARMSTRONG NUMBER";
    }
    else
    {
        cout<<"NOT A ARMSTRONG NUMBER";
    }
}