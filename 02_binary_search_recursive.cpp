class Solution {
  public:
    int b_s(int arr[],int s,int e,int k){
        
        if(s<e){return -1;}
        
        int mid = s+(e-s)/2;
        
        if(arr[mid] == k){return mid;}
        
        return( (arr[mid] > k) ? b_s(arr,s,mid-1,k) : b_s(arr,mid+1,e,k) );
    }
    int binarysearch(int arr[], int n, int k) {
        // code here
        
        int s = 0;
        int e = n-1;
        
        return b_s(arr,s,e,k);
        
    }
};