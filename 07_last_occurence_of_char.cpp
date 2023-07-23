#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int find_last_occu(string&s,int&n,int i,char target){

    if(i>=n){return -1;}

    if(s[i] == target){return i;}

    return find_last_occu(s,n,i-1,target);
}
int main() {
    
    // finding last occuerence using recursion

    string s = "jingalala";
    int n = s.length();
    int i = n-1;
    char target = 'g';

    int ans = find_last_occu(s,n,i,target);
    cout<<ans<<endl;

    return 0;
}