#include<iostream> 
#include<bits/stdc++.h>
using namespace std;

unordered_map<int,bool> rowCheck;
unordered_map<int,bool> leftUpperDiagnolCheck;
unordered_map<int,bool> leftLowerDiagnolCheck;

void print_ans(vector<vector<char>>& board,int n){

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
}


bool is_Safe(vector<vector<char>>& board,int row,int col,int n){

    if(rowCheck[row] == true or leftLowerDiagnolCheck[n-1 + col-row] ==true or leftUpperDiagnolCheck[row+col] == true){
        return false;
    }

    // int i = row;
    // int j = col;

    // // check on left row -> i , j-1
    // while(j>=0){
    //     if(board[i][j]=='Q'){
    //         return false;
    //     }
    //     j--;
    // }

    // // check on upper left diagnol -> i-1 , j-1
    // i = row;
    // j = col;
    // while(i>=0 and j>=0){
    //     if(board[i][j]=='Q'){
    //         return false;
    //     }
    //     i--;
    //     j--;
    // }

    // // check on bottom left diagnol -> i+1 , j-1
    // i = row;
    // j = col;
    // while(i<n and j>=0){
    //     if(board[i][j]=='Q'){
    //         return false;
    //     }
    //     i++;
    //     j--;
    // }
    return true;

}

void solve(int col,vector<vector<char>>& board,int n){

    // base case
    // columns are over
    if(col>=n){
        print_ans(board,n);
        return;
    }

    // check for every row in given column
    for(int row = 0;row<n;row++){
        if(is_Safe(board,row,col,n)){

            // place Queen
            board[row][col] = 'Q';
            rowCheck[row] = true;
            leftUpperDiagnolCheck[row+col] = true;
            leftLowerDiagnolCheck[n-1 + col-row] = true;
            // recursive call
            solve(col+1,board,n);
            // backtrack
            board[row][col] = '-'; // we are backtracking because we want all solutions not single
            rowCheck[row] = false;
            leftUpperDiagnolCheck[row+col] = false;
            leftLowerDiagnolCheck[n-1 + col-row] = false;
        }
    }

}


int main(){

    int n = 4;
    vector<vector<char>> board (n,vector<char>(n,'-'));

    int col = 0;// we are starting from 1st column

    solve(col,board,n);

}