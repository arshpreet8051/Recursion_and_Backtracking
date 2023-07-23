#include<vector>
using namespace std;


class Solution {
public:
    void solve(vector<int>&arr,vector<vector<int>>&ans,vector<int>&temp,int t,int i){


        // base case
        if(t==0){
            ans.push_back(temp);
            return;
        }

        if(t<0){
            return;
        }

        for(int x = i;x<arr.size();x++){
            temp.push_back(arr[x]);
            solve(arr,ans,temp,t-arr[x],x);
            temp.pop_back();
        }


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int i = 0;

        solve(candidates,ans,temp,target,i);

        return ans;
    }
};