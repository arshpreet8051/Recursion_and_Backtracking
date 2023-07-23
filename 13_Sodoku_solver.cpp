#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    bool is_Safe(char value,int curr_row,int curr_col,vector<vector<char>>& board){

        for(int i = 0;i<9;i++){

            // row check
            if(board[curr_row][i] == value){return false;}

            // column check
            if(board[i][curr_col] == value){return false;}

            // 3 x 3 box check
            if(board[3*(curr_row/3) + (i/3)] [3*(curr_col/3) + (i%3)] == value){return false;}
        }

        return true;
    }
    bool solve(vector<vector<char>>& board){

        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){

                if(board[i][j]  == '.'){
                    for(int value = '1';value<='9';value++){
                        if(is_Safe(value,i,j,board)){
                            board[i][j] = value;

                            if(solve(board) == true){
                                return true;
                            }
                            else{
                                board[i][j] = '.'; // backtrack
                            }
                        }
                    }
                    return false;
                }

            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};