#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge_it(vector<int>&v,int s,int mid,int e){

    int len1 = mid-s+1;
    int len2 = e-mid;

    vector<int> left(len1);
    vector<int> right(len2);

    // copy values
    int k = s;
    for(int i = 0;i<len1;i++){
        left[i] = v[k++];
    }

    k = mid+1;
    for(int i = 0;i<len2;i++){
        right[i] = v[k++];
    }

    int ind1 = 0;
    int ind2 = 0;
    k = s;

    while(ind1<len1 and ind2<len2){
        if(left[ind1] <= right[ind2]){
            v[k++] = left[ind1++];
        }
        else{
            v[k++] = right[ind2++];
        }
    }

    while(ind1<len1){
        v[k++] = left[ind1++];
    }

    while(ind2<len2){
        v[k++] = right[ind2++];
    }
}

void merge_sort(vector<int>&v,int s,int e){
    if(s>=e){return;}

    int mid = s+(e-s)/2;

    merge_sort(v,s,mid);
    merge_sort(v,mid+1,e);

    merge_it(v,s,mid,e);
}

int main(){

    vector<int> v = {34,42,2,43,1,34,7,987,2};
    int n = v.size();

    cout<<"Before Sorting : "<<endl;
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    merge_sort(v,0,n-1);

    cout<<"After Sorting : "<<endl;
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    
}