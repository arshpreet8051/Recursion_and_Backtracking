#include<bits/stdc++.h>
using namespace std;

// given array find maximum sum of non adjacent elements

void solve(vector<int>&arr,int i,int sum,int &maxi){

    //base case
    if(i>=arr.size()){
        //update maxi
        maxi = max(maxi,sum);
        return;
    }

    // include
    //when inclded move i by 2 and increase the sum
    solve(arr,i+2,sum+arr[i],maxi);

    //exclude
    solve(arr,i+1,sum,maxi);
}
int main(){

    vector<int> v = {1,2,4};
    // ans should be 5

    int sum = 0;
    int i = 0;
    int maxi = INT_MIN;

    solve(v,i,sum,maxi);

    cout<<"answer : "<<maxi<<endl;

}