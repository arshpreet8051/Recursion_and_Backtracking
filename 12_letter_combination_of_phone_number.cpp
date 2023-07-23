#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    void solve(string &digits,string mp[],vector<string>&ans,string output,int i,int n){

        // base case
        if(i>=n){
            ans.push_back(output);
            return;
        }

        // include char
        
        // string str = mp.at(digits[i]);
        int ind = digits[i]-'0';
         string str = mp[ind];

        for(int itr = 0;itr<str.length();itr++){
            
            output.push_back(str[itr]);

            solve(digits,mp,ans,output,i+1,n);

            output.pop_back(); // backtrack
        }
    }
    vector<string> letterCombinations(string digits) {

        if(digits.length() <= 0){return {};}

        string mp[10];
        
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        int n = digits.length();
        int i = 0;
        vector<string> ans;
        string output = "";
        solve(digits,mp,ans,output,i,n);
        return ans;
    }
};