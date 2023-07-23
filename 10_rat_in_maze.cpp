#include<iostream> 
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i,int j,int row,int col,int arr[3][3],vector<vector<bool>>&visited){

    if( ( (i>=0 and i<row) and (j>=0 and j<col)) and (visited[i][j] == false) and (arr[i][j]==1)){
        return true;
    }
    else{
        return false;
    }
}

void rat_in_maze(int arr[3][3],int row,int col,int i,int j,vector<vector<bool>>&visited,vector<string>&ans,string output){

    // base case
    if(i == row-1 and j == col-1){
        ans.push_back(output);
        return;
    }

    // up -> i-1,j
    
    if(isSafe(i-1,j,row,col,arr,visited)){
        visited[i-1][j] = true;
        rat_in_maze(arr,row,col,i-1,j,visited,ans,output+'U');
        // backtracking
        visited[i-1][j] = false;
    }

    // down -> i+1,j
    if(isSafe(i+1,j,row,col,arr,visited)){
        visited[i+1][j] = true;
        rat_in_maze(arr,row,col,i+1,j,visited,ans,output+'D');
        // backtracking
        visited[i+1][j] = false;
    }

    // left -> i,j-1
    if(isSafe(i,j-1,row,col,arr,visited)){
        visited[i][j-1] = true;
        rat_in_maze(arr,row,col,i,j-1,visited,ans,output+'L');
        // backtracking
        visited[i][j-1] = false;
    }

    // right -> i,j+1
    if(isSafe(i,j+1,row,col,arr,visited)){
        visited[i][j+1] = true;
        rat_in_maze(arr,row,col,i,j+1,visited,ans,output+'R');
        // backtracking
        visited[i][j+1] = false;
    }

}


int main(){


    int maze[3][3] = { {1,0,0}, {1,1,0}, {1,1,1} };

    int row = 3;
    int col = 3;

    vector<vector<bool>> visited (row,vector<bool>(col,false));
    vector<string> ans;
    string output = "";

    if(maze[0][0]==0){cout<<"No Path";}

    rat_in_maze(maze,row,col,0,0,visited,ans,output);

    for(auto x : ans){
        cout<<x<<endl;
    }

}