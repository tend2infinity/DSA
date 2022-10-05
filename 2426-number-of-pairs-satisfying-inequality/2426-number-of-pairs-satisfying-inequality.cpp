class Solution {
public:
    long long merge(int l, int mid, int r, vector<int>& nums,int diff){
            int i=l;
            int j=mid+1;
            long long count=0; 
            while(j<=r){
            while(i<=mid && nums[i]<= (nums[j]+diff) ){
                i++;
            }
            count += i-l;
            j++;    
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
    
     long long mergeSort(int l, int r, vector<int>& nums, int diff){
        if(l>=r)
            return 0; 
        int mid = l+ (r-l)/2;
        long long count = mergeSort(l,mid,nums,diff);
        count += mergeSort(mid+1,r,nums,diff);
        count += merge(l,mid,r,nums,diff);
        return count;
    }
    
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int> arr;
        for(int i=0; i<nums2.size(); i++){
            arr.push_back(nums1[i]-nums2[i]);
        }
        return mergeSort(0,arr.size()-1, arr,diff);
    }

};