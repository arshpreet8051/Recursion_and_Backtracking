#include<bits/stdc++.h>
using namespace std;


int fact(int n){
    
    //base case
    if(n==0 or n==1){return 1;}

    return n * fact(n-1);
}

// Time complexity = O(N);
// Space complexity = O(N); could have been O(1) in iterative approach

int main(){

    cout<<fact(6);
}