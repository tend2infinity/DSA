class Solution {
public:
    bool recur(int index, vector<int>& nums, vector<int>& dp){
        //base
        if(index == nums.size()-1)
            return true;
        if(index>=nums.size())
            return false;
        if(dp[index]!= -1)
            return dp[index];
        
        int maxJump = nums[index];
        if(maxJump == 0)
            return dp[index] = false;

        bool res = false;
        while(maxJump){
            res = res || recur(index+maxJump,nums,dp);
            maxJump--;
        }            
        
        return dp[index] = res;
        
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(1e5,-1);
        return recur(0,nums,dp);
    }
};