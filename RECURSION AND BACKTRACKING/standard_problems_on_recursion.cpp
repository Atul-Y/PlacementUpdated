
//---------------TOWER OF HANOI-------------------


// Rules : 1 only one disk transfer in one step 
//         2 samller disk is always kept on top of the larger disk


// #include <bits/stdc++.h>
// using namespace std;
// void towerOfHanoi(int n,string source,string helper,string destination)
// {

//     if(n==1)
//     {
//        cout<<"transfer disk "<<n<<" from "<<source<< " to "<<destination<<endl;
//        return;
//     }
//     towerOfHanoi(n-1,source,destination,helper);
//     cout<<"transfer disk "<<n<<" from "<<source<< " to "<<destination<<endl;
//     towerOfHanoi(n-1,helper,source,destination);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     string source="S",helper="H",destination="D";
//     towerOfHanoi(n,source,helper,destination); 
// } 


//----------print string in reverse----------------------------------------------------------------
// #include <bits/stdc++.h>
// using namespace std;
// void reversestring(string str,int i)
// {
//     if(i<0)
//     return;

//     cout<<str[i]<<" ";
//     reversestring(str,i-1);
// }
// int main()
// {
//     string str="abcd";
//     reversestring(str,str.length());
// }

//--------find the 1st and last occurance of an element in a string-------------------------

// #include <bits/stdc++.h>
// using namespace std;
// static int first=-1,last=-1;

// void firstLastOccurance(string str,char element,int i)
// {

//     if(str[i]=='\0') //base case
//     {
//         cout<<first<<" "<<last;
//         return;
//     }


//     if(str[i]==element)
//     {
//         if(first==-1)   //bs ek hi baar first me pata chal jaega
//         first=i;
//         else
//         last=i;  //agar first nahi pata chala to last i k sath bdega aur last element found hi last hoga
//     }
//     firstLastOccurance(str,element,i+1);
// }
// int main()
// {
//     string str="geeksforgeeks";
//     char element='e';
//     firstLastOccurance(str,element,0);
// }

//--------check if an array is strictly increasing-------------

// #include <bits/stdc++.h>
// using namespace std;


// bool checkstricltyincreasing(int arr[],int i)
// {
//     if(i==0)  //base case
//     return true;

//     if(arr[i-1]<arr[i])
//     return checkstricltyincreasing(arr,i-1);
//     else
//     return false;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     cout<<checkstricltyincreasing(arr,n-1);
// }



//------------------- Move all 'x' in a string to the end of string-------------------

// #include <bits/stdc++.h>
// using namespace std;

// void MoveAllX(string str,int count,int i,string newstr)
// {

//     if(str[i]=='\0')   // base case   
//     {
//         for(int j=0;j<count;j++)
//         {
//             newstr += 'x';
//         }
//         cout<<newstr<<endl;
//         return;
//     }


//     if(str[i]=='x')
//     count++;
//     else
//     newstr=newstr+str[i];
//     MoveAllX(str,count,i+1,newstr);
// }
// int main()
// {
//     string str="axbcxxxx";
//     string newstr="";
//     MoveAllX(str,0,0,newstr);

// }


//----------remove duplicates in a string--------------------------------

// 1> create a map memory of 26 alphabets
// 2> fill all map with false values
// 3> now recurse and check and upadte newstring with conditions--if(map[i]==t) do not push_back in newstring 
// 
// now give base condition                                                                if(map[i]==f) push_back in new string                 
// #define SIZE 26    
// #include <bits/stdc++.h>
// using namespace std;

// int freq[SIZE]={'F'};
// void RemoveDuplicate(string str,string newstr,int i)
// {
//     if(str[i]=='\0')
//     {
//         cout<<newstr<<endl;
//         return;
//     }


//     if(freq[str[i]-'a']=='T'){
//         RemoveDuplicate(str,newstr,i+1);
//     }
//     else{
//         newstr +=str[i];
//         freq[str[i]-'a']='T';
//         RemoveDuplicate(str,newstr,i+1);
//     }
// }

// int main()
// {
//     string str="geeksforgeeks";
//     RemoveDuplicate(str,"",0);
// }


//----------print all subsequences of a string------------
//  note subsequence is that where a letter which first cannot come before

// LOGIC:
// 1> create newstring
// 2> choice 1 want to push_back to newstring then--call1=newstring+str[i]
// 3> choice 2 dont want to push_back so---call2=newstring
 
//  #include <bits/stdc++.h>
//  using namespace std;

//  void subsequences(string str,int i,string newstr)
//  {

//     if(str[i]=='\0'){
//         cout<<newstr<<endl;   //jaise hum tree me output print krte hai waisahi output print horaha....tree me hum pehle left wale print ho jate de jab tak katam ho data similarly yaha bhi jab tak str[i] katam na ho 
//         return;
//     }
//     // to be
//     subsequences(str,i+1,newstr+str[i]);  

//     // or not to be 
//     subsequences(str,i+1,newstr);
//  }
//  int main()
//  {
//     string str="123";
//     subsequences(str,0,"");
//  } 


 // ----print all unique subsequences of a string------------

//  1> follow the logic of subsequence recursion and take set and check if(set.contains(newstr)==true) then just return
//  2>  else cout<<newstr aur set me push_back krte raho set.insert(newstr)


// #include <bits/stdc++.h>
// using namespace std;
// void print_unique_subsequences(string str,string newstr,int i,set<string>s){

//     if(str[i]=='\0'){
//         if(s.find(newstr)!=s.end()){ // agar pehle se hai toh return krjao  
//             return;
//         }
//         else{
//             cout<<newstr<<endl;
//             s.insert(newstr);
//             return;
//         }
//     }
//     print_unique_subsequences(str,newstr+str[i],i+1,s);

//     print_unique_subsequences(str,newstr,i+1,s);
// }
// int main()
// {
//     string str="AA";
//     set<string>s;

//     print_unique_subsequences(str,"",0,s);
// }


//print keypad combination-----------
//make tree for the quetion to understang visualy and think in recursive tree manner

// #include <bits/stdc++.h>
// using namespace std;
// static string freq[]={".","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};

// void print_combination(string str,int i,string combination){

//     //base case
//     if(i==str.length()){
//         cout<<combination<<" ";
//         return;
//     }
     
//     string mapping=freq[str[i]-'0'];

//     for(int k=0;k<mapping.length();k++){
//         print_combination(str,i+1,combination+mapping[k]);
//     }

// }
// int main()
// {
//     string str="678";
//     print_combination(str,0,"");
// }



//advanced level reecursion problems -----------------

//-------------------print all perrmutation of a string ----------------------------

// #include <bits/stdc++.h>
// using namespace std;
// void print_permutation(string str,string newstr){

//     if(str.length()==0){
//         cout<<newstr<<endl;
//         return;
//     }

//     for(int i=0;i<str.length();i++){
//         print_permutation(str.substr(0,i)+str.substr(i+1),newstr+str[i]);
//     }
// }
// int main()
// {
//     string str="ABC";
//     print_permutation(str,"");

// }


//---------count the paths in a maze from (0.0) to (n,m) given condition that we can only move either in right or downward direction----------------------------------------------------------------


// #include <bits/stdc++.h>
// using namespace std;

// int count_paths(int i,int j,int n,int m){                                          //you can optimize like a dp problem which says ---save the value of count at each dp[i][j] so that if again we come that point we ca simply take saved value instaed of again recursing whole

//     //base case
//     if(i==n-1 && i==m-1)
//     return 1;            //dono hi base conditions hai 
//     if(n==0 || m==0)
//     return 0;

//     int down_paths=count_paths(i+1,j,n,m);

//     int right_paths=count_paths(i,j+1,n,m);

//     return down_paths+right_paths;
// }
// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     cout<<count_paths(0,0,n,m);
// }


//-----tilling problem=> Find number of ways to Place tiles of size 1Xm in a floor of size nXm-----

// #include <bits/stdc++.h>
// using namespace std;
// int place_tiles(int n,int m){

//     //base case

//     if(n==m)
//     return 2;

//     if(n<m)  //ie in this case we could not place in horizontal
//     return 1;

//     int vertical_placement =place_tiles(n-m,m);  //n-m becoz if placed vertical then we could only place vertical tiles in adjacent to it

//     int horizontal_placement =place_tiles(n-1,m);

//     return vertical_placement+horizontal_placement;

// }
// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     cout<<"no of ways to place_tiles is  "<<place_tiles(n,m);

// }


//-----friends pairing problem------------------------we can only have single and pair friend combinations
// 1>-select first friend and n-1 friends possiblities
// 2>-select first and make it pair with either n-1 left friend and multiply that with left friends that will give all other possiblitiesas as well

// #include <bits/stdc++.h>
// using namespace std;

// int friends_pairing_count(int n){

//     if(n<=1)
//     return 1;

//     int way1=friends_pairing_count(n-1);

//     int way2=(n-1) * friends_pairing_count(n-2);

//     return way1 + way2;
// }
// int main()
// {
//     int n=4;
//     cout<<friends_pairing_count(n);
// }


//-------------------- get stair paths----------------
// 1. You are given a number n representing number of stairs in a staircase.
// 2. You are standing at the bottom of staircase. You are allowed to climb 1 step, 2 steps or 3 steps in one move.

#include<iostream>
#include <bits/stdc++.h>
using namespace std;
vector<string> getStairPaths(int n) {
    if(n==0){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }
    else if(n<0){
        vector<string> bres;
        return bres;
    }
    
    vector<string> rres1 = getStairPaths(n - 1);
    vector<string> rres2 = getStairPaths(n - 2);
    vector<string> rres3 = getStairPaths(n - 3);
    vector<string> mres;

    for(string rstr: rres1){
        mres.push_back("1" + rstr);
    }
    for(string rstr: rres2){
        mres.push_back("2" + rstr);
    }

    for(string rstr: rres3){
        mres.push_back("3" + rstr);
    }

    return mres;
}

int main(){
     int n;
     cin>>n;
     vector<string> paths = getStairPaths(n);
     int total_no_of_ways=0;
     for(int i=0; i<paths.size(); i++){
        cout<<paths[i]<<" ";
        total_no_of_ways++;
     }
    cout<<"-----"<<total_no_of_ways;
}


                        
                                