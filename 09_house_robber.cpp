#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// robber cannot rob any 2 adjacent houses
// apply include-exclude principle

int max_profit(vector<int>& arr,int i){

    // base case
    if(i>=arr.size()){return 0;}

    return max(arr[i]+max_profit(arr,i+2),max_profit(arr,i+1));
}
int main(){
    vector<int> nums = {1,2,3,1};
    int ans = max_profit(nums,0);
    cout<< ans;
}