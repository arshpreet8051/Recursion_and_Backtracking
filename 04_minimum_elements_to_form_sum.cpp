#include<bits/stdc++.h>
using namespace std;

// Lakshay Bhaiya Adobe Online Test Question
// Given array of numbers and target sum
// return minimum numbers to form the given target sum

int solve(vector<int>&arr,int target){

    //base case 1:
    if(target == 0){return 0;}

    if(target<0){return INT_MAX;}

    int mini = INT_MAX;
    for(int i = 0;i<arr.size();i++){
        int ans = solve(arr,target-arr[i]);
        if(ans!=INT_MAX){
            mini = min(mini,ans+1);
        }
    }
    return mini;
}

int another_approach(vector<int>&arr,int target,int x){

    if(x==target){return 0;}
    if(x>target){return -1;}

    int mini = INT_MAX;
    for(int i = 0;i<arr.size();i++){
        int ans = another_approach(arr,target,x+arr[i]);
        if(ans!=-1){
            mini = min(mini,ans+1);
        }
    }
    return mini;

}

int main(){

    vector<int> arr = {1,2};
    int target = 5;

    cout<<"Answer is : "<<another_approach(arr,target,0)<<endl;
}
