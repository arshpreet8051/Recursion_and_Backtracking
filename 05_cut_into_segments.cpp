#include<bits/stdc++.h>
using namespace std;

// given a rod of length of n
// you can cut the rod only of length of 'x' , 'y' , 'z' 
// return maximum number of pieces you can cut into

int solve(int n,int x,int y,int z){
    

    // base case 1:
    if(n==0){return 0;}

    // base case 2:
    if(n<0){return INT_MIN;}

    int a1 = solve(n-x,x,y,z)+1;
    int a2 = solve(n-y,x,y,z)+1;
    int a3 = solve(n-z,x,y,z)+1;

    int ans = max(a1,max(a2,a3));


    return ans;
}
int main(){

    int n = 7;
    int x = 5;
    int y = 2;
    int z = 2;

    int ans = solve(n,x,y,z);

    if(ans < 0){
        ans = 0;
    }

    

    cout<<"Answer is : "<<ans<<endl;
}