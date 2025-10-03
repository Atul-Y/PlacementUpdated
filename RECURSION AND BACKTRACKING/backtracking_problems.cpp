

//-------N-Queens problem------------------------

// #include <bits/stdc++.h>
// using namespace std;
// const int n=4;  // OR #define n 4


// bool issafe(int arr[n][n],int row ,int col){

//     for(int i=row-1,j=col;i>=0;i--,j){ //  uper check krne me matrix me j toh same rahega ie j=col (no change to col)
//         if(arr[i][j]==1){
//             return false;
//         }
//     }

//     for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){   //checking diagnoly left
//         if(arr[i][j]==1){
//             return false;
//         }
//     }

//     for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){  //checking diagnoly right
//         if(arr[i][j]==1){
//             return false;
//         }
//     }

//     return true;

// }
// void printNQueens(int arr[n][n],string qsf,int row){

//     if(row==n){
//         cout<<qsf+"."<<endl;
//         return;

//     }


//     for(int col=0;col<n;col++){    //n is the size of matrix as it given same row and col
//         if(issafe(arr,row,col)==true){
//             arr[row][col]=1;
//             printNQueens(arr,  qsf + to_string(row)+ "-" + to_string(col) + ", ", row+1);
//             arr[row][col]=0;
//         }
//     }
// }


// int main()
// {
//     int arr[n][n];
//     printNQueens(arr,"",0);  // we have given row =0 becoz we will take each level as row and for that row we possiblities as coloumns ie har ek row k liye choose karege colums
// }



//------------------------------rat in a maze problem---here we need to find paths not paths count-----------------------------
// #include <bits/stdc++.h>
// using namespace std;
// void printMazePaths(int sr,int sc,int dr,int dc,string psf){

//     if(sr>dr || sc>dc)
//     return;


//     if(sr==dr && sc==dc){
//         cout<<psf<<endl;
//         return;
//     }


//     printMazePaths(sr,sc+1,dr,dc,psf+"h");
//     printMazePaths(sr+1,sc,dr,dc,psf+"v");
// }

// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,m;
//     cin>>n>>m;
//     printMazePaths(1,1,n,m,"");
// }


//---------knight tour problem------------tour around all moves where you can find the given nxn moves eg if n=5 then total moves should be 25 


#include <bits/stdc++.h>
using namespace std;

void displayBoard(vector<vector<int>> chess){
    cout<<endl;
    for(int i=0; i<chess.size(); i++){
        for(int j=0; j<chess.size(); j++){
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printKnightTour(vector<vector<int>> &chess,int n,int r,int c,int move){
    
    if(r<0 || c<0 || r>=n || c>=n || chess[r][c]!=0)
    return;

    if(move==n*n){
        chess[r][c]=move;
        displayBoard(chess);
        chess[r][c]=0;
        return;
    }    
    
    chess[r][c]=move;
    printKnightTour(chess,n,r-2,c+1,move+1);
    printKnightTour(chess,n,r-1,c+2,move+1);
    printKnightTour(chess,n,r+1,c+2,move+1);
    printKnightTour(chess,n,r+2,c+1,move+1);
    printKnightTour(chess,n,r+2,c-1,move+1);
    printKnightTour(chess,n,r+1,c-2,move+1);
    printKnightTour(chess,n,r-1,c-2,move+1);
    printKnightTour(chess,n,r-2,c-1,move+1);
    chess[r][c]=0;

}
int main(){
    int n,r,c;
    cin>>n>>r>>c;
    vector<vector<int>> chess(n,vector<int>(n,0));
    printKnightTour(chess,n,r,c,1);
    
}