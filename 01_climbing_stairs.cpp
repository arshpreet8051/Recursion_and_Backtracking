#include<bits/stdc++.h>

// recursive approach 
// TLE mrda

// either you can move 1 step or 2 step
// count ways to reach the nh stairs

int count_ways(int n){

    // ways to reach 0th stair -> jump from 0 to 0 -> ways -> 1
    // ways to reach 1st stair -> from 0th to 1st -> ways -> 1

    if(n==0 or n==1){
        return 1;
    }

    int ans = count_ways(n-1) + count_ways(n-2);
    return ans;
}