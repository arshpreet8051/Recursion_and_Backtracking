#include<bits/stdc++.h>
using namespace std;

// Combination sum leetcode

class Solution {
public:
    void solve(vector<int>& candidates,vector<vector<int>>&ans,vector<int> temp, int t,int sum,int i){

        // base case
        if(sum==t){
            ans.push_back(temp);
            return;
            }
        
        if(i>=candidates.size() or sum>t){
            return;
        }

        sum = sum + candidates[i];
        temp.push_back(candidates[i]);

        solve(candidates,ans,temp,t,sum,i);
        sum = sum-candidates[i];
        temp.pop_back();
        
        solve(candidates,ans,temp,t,sum,i+1);

        sum = sum-candidates[i];
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        int i = 0;
        solve(candidates,ans,temp,target,sum,i);
        return ans;

    }
};