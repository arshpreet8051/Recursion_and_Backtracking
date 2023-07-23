#include<bits/stdc++.h>
using namespace std;

// Power Set
// Given a string S, Find all the possible subsequences of the String in lexicographically-sorted order.
// Include - Exclude pattern

vector<string> all_subsequences(string s){

    vector<string> ans;
    string sample = "";
    int i = 0;

    solve(s,i,sample,ans);
    return ans;
}

void solve(string s,int i,string sample,vector<string>&ans){

    // base case
    if(i>=s.length()){
        if(sample!=""){
            ans.push_back(sample);
        }
    }

    // exclude case
    solve(s,i+1,sample,ans);

    // include case
    sample+=s[i];

    solve(s,i+1,sample,ans);
}


// Power Set Without Duplicates

class Solution {
public:
 void solve(vector<int> nums,int index,vector<int> output,vector<vector<int>>& ans){
        
        //base case
       
        if(index>=nums.size()){
            
            sort(output.begin(),output.end());
            auto it = std::find(std::begin(ans),std::end(ans),output);
            if(it!=std::end(ans)){
                ans.erase(it);
                }

            
            ans.push_back(output);
            return;
        }
        
        //excluding
        solve(nums,index+1,output,ans);
            
        //including
        int element = nums[index];
        output.push_back(element);
        solve(nums,index+1,output,ans);    
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> output;
        vector<vector<int>> ans;
        int index = 0;
        solve(nums,index,output,ans);
        //sort(ans.begin(),ans.end());
        return ans;
    }
};