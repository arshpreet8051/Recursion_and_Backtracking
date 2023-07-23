class Solution {
public:

    // using gap method to sort in place -> other option -> Heap sort

    void gap_function(vector<int>& nums,int s,int mid,int e){
        
        int len1 = mid-s+1;
        int len2 = e-mid;

        int total_size = len1+len2;

        int gap = (total_size/2) + (total_size%2); // here modulo % is done to get ceil value

        

        while(gap > 0){
            
            int i = s;
            int j = i+gap;

            while(j<=e){

                if(nums[i] > nums[j]){
                    swap(nums[i],nums[j]);
                    
                }
                i++;
                j++;
            }

            if(gap == 1){break;}

            gap = (gap/2) + (gap%2); // here modulo % is done to get ceil (rounded off) value
        }

    }

    void merge_sort(vector<int>& nums,int s,int e){

        if(s>=e){return;}

        int mid = s+(e-s)/2;

        merge_sort(nums,s,mid);
        merge_sort(nums,mid+1,e);

        gap_function(nums,s,mid,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        
        int s = 0;
        int e = nums.size()-1;

        merge_sort(nums,s,e);

        return nums;
    }
};