#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void print_subarrays(vector<int>&v,int s){

    if(s>=v.size()){return;}

    int end = s;
    while(end<v.size()){
        for(int i = s;i<=end;i++){
            std::cout<<v[i]<<" ";
        }
        std::cout<<endl;
        end++;
    }

    print_subarrays(v,s+1);

}

int main(){

    // challenge print all subarrays for the below vector using recursion
    vector<int> sample = {1,2,3,4,5};
    print_subarrays(sample,0);
}