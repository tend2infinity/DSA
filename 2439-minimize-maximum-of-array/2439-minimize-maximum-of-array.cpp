class Solution {
public:
    bool test(int maxi, vector<int>& nums){
        long long extra=0;
        for(auto x: nums){
            if(x<maxi){
                extra+=maxi-x;
            }else{
                if(x-maxi>extra)
                    return false;
                extra-=(x-maxi);
            }
        }
        return true;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int l=0;
        int r = (int)1e9;
        int mid=0;
        int ans=mid;
        while(l<=r){
            mid = l+ (r-l)/2;
            if(test(mid,nums)){
                ans = mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};