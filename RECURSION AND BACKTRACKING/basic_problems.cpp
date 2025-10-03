// ---------------- Print your name 5 times

// #include <bits/stdc++.h>
// using namespace std;

//void printname(int i,int n)
// {
//     if(i>n)
//     return;

//     cout<<"Atul"<<" ";

//     printname(i+1,n);
// }

// int main()
// {
//     int n;
//     cin>>n;
//     printname(1,n);
    
// }


//-----------print linearly from 1 to N----------------------------------

// #include <bits/stdc++.h>
// using namespace std;


// void printlinearly(int i,int n)
// {
//     if(i>n)
//     return;

//     cout<<i<<" ";

//     printlinearly(i+1,n);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     printlinearly(1,n);
// }

//print N to 1 eg 1 2 3 4 5 so the ans is 5 4 3 2 1 

// #include <bits/stdc++.h>
// using namespace std;
// void printfromNto1(int n)
// {
//     if(n<1)
//     return;

//     cout<<n<<" ";
//     printfromNto1(n-1);
// }
// int main()
// {
//     int n;
//     cin>>n;
//      printfromNto1(n);
// }

//print sum of first natural numbers----------------------------------------------------------------

// #include <bits/stdc++.h>
// using namespace std;
// void printfirstnaturalsum(int i,int n,int sum)
// {
//     if(i>n)
//     {
//         cout<<sum<<" ";
//         return;
//     }
    
//     sum=sum+i; 
//     printfirstnaturalsum(i+1,n,sum);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     printfirstnaturalsum(1,n,0);
// }


//----factorial of a number----------------------------------------------------------------

// #include <bits/stdc++.h>
// using namespace std;

// int printFactoral(int n)
// {
//     if(n==0 || n==1)
//     return 1;
    
//     return n*printFactoral((n-1));
// }
// int main()
// {
//     int n;
//     cin>>n;
//     cout<<printFactoral(n);

// }


// //--------finbonacci sequence till nth term----------------------------------------------------------------

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// void fabonacci(int a,int b,int n)
// {

//     if(n==0)
//     return;

//     int c=a+b;
//     cout<<c<<" ";

//     a=b;
//     b=c;
//     fabonacci(a,b,n-1);
// }



// int main()
// {
//     int a=0,b=1,c;
//     cout<<a<<" "<<b<<" ";
//     c=a+b;

//     //we will print 7th factorial
//     int n=7;
//     fabonacci(a,b,n-2);
//     return 0;
// } 


// Print x^n (stack height=n)---------------------------
// 1> x^n=x*x^n-1

// #include <bits/stdc++.h>
// using namespace std;
// int printheight(int n,int x)
// {
//     if(n==0)  //base case 1
//     return 1;

//     if(x==0)  // base case 2
//     return 0;


//     int power=printheight(n-1,x);
//     return x*power;

// }

// int main()
// {
//     int n,x;
//     cin>>n>>x;
//     cout<<printheight(n,x);
// }


// print x^n (stack height=logn)

#include <bits/stdc++.h>
using namespace std;
int printheight(int n,int x)
{
    if(n==0)  //base case 1
    return 1;

    if(x==0)  // base case 2
    return 0;

    int power;
    if(n%2==0){
    power=printheight(n/2,x) * printheight(n/2,x);
    return power;
    }
    else{
    power=printheight(n/2,x) * printheight(n/2,x);   //this concept is easy and can can be applied to many problems
    return x*power;
    }
}
int main()
{
    int n,x;
    cin>>n>>x;
    cout<<printheight(n,x);
}