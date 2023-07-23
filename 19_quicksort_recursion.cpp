#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr,int s,int e){

    // find pivot
    int pivot = s;

    // find right position of pivot
    int count  = 0;
    for(int i = s+1;i<=e;i++){ // s+1 coz s is pivot itself
        if(arr[i] <= arr[pivot]){count++;}
    }

    int right_index = s + count;

    swap(arr[right_index],arr[pivot]);
    pivot = right_index;

    // pivot de right ch saare smaller and pivot de right te saare larger

    int i = s;
    int j = e;

    while(i < pivot and j > pivot){

        while(arr[i]<=arr[pivot]){
            i++;
        }
        while(arr[j]>arr[pivot]){
            j--;
        }

        // Hun ethe aake 2 case bnde ne
        // 1 -> we have got elements to swap
        // 2 -> i and j are exhausted

        if(i<pivot and j>pivot){
            swap(arr[i],arr[j]);
        }
    }

    return pivot;
}

void quick_sort(vector<int>&arr,int s,int e){

    if(s>=e){return;} //handling invalid arrays and single element casses

    // partiton logic
    int pivot = partition(arr,s,e);

    // recursive calls

    // left
    quick_sort(arr,s,pivot-1);

    // right
    quick_sort(arr,pivot+1,e);
}
int main(){

    vector<int> v = {985,2,34,1,234,4,124};

    cout<<"Before Sorting : "<<endl;
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    quick_sort(v,0,v.size()-1);

    cout<<"After Sorting : "<<endl;
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

}