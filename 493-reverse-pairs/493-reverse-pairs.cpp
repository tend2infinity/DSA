class Solution {
public:
    int merge(int l, int mid, int r, vector<int>& nums){
        int i = l;
        int j = mid+1;
        int count = 0;
        while(i<=mid){
        while(j<=r && nums[i]> 2LL*nums[j]){
                j++;
            }
            count += j-(mid+1);
            i++;
        }
        vector<int> temp;
        i=l;
        j=mid+1;
        while(i<=mid && j<=r){
            if(nums[i]<=nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }
        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=r){
            temp.push_back(nums[j++]);
        }
        for(int ptr=l; ptr<=r; ptr++){
            nums[ptr] = temp[ptr-l];
        }
        return count;
    }
    
    int mergeSort(int l, int r, vector<int>& nums){
        if(l>=r)
            return 0; 
        int mid = l+ (r-l)/2;
        int count = mergeSort(l,mid,nums);
        count += mergeSort(mid+1,r,nums);
        count += merge(l,mid,r,nums);
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(0,nums.size()-1, nums);
    }
};