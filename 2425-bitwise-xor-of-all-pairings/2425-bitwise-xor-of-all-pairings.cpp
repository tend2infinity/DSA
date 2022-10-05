class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        if(nums1.size()%2==0 && nums2.size()%2==0)
            return 0;
        else if(nums1.size()%2!=0 && nums2.size()%2==0){
            for(auto x:nums2){
                ans^=x;
            }
        }
        else if(nums1.size()%2==0 && nums2.size()%2!=0){
            for(auto x:nums1){
                ans^=x;
            }
        }
        else{
            int ans1 = 0;
            int ans2=0;
            for(auto x: nums1)
                ans1^=x;
            for(auto x: nums2)
                ans2^=x;
            ans = ans1^ans2;
        }
        return ans;
    }
};