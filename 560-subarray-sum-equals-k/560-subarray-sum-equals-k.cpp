class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> preSum (nums.size(),0);
        preSum[0] = nums[0];
        unordered_map<int,int> map;
        int ans=0;
        map[0]= 1;
        for(int i=1; i<nums.size(); i++){
            preSum[i] = preSum[i-1] + nums[i];
        }

        for(int i=0; i<preSum.size(); i++){
            if(map[preSum[i]-k]>0)
                ans+= map[preSum[i]-k];
            map[preSum[i]]++;
        }

        return ans;
    }
};