class Solution {
public:
    int util(int i, int p, vector<int> &nums, vector<vector<int>> &dp){
        if(i==0)    return dp[i][p] = p==nums.size() ? 1 : nums[i]<nums[p];
        
        if(dp[i][p]!=-1) return dp[i][p];
        
        int take = 0;
        int notTake = util(i-1, p, nums, dp);
            
        if(p==nums.size() or nums[i]<nums[p]){
            take = 1 + util(i-1, i, nums, dp);
        }
        
        return dp[i][p] = max(notTake, take);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return util(n-1, n, nums, dp);
    }
};