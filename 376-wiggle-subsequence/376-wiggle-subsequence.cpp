class Solution {
public:
    
    int dp[1005][2];
    
    int helper(vector<int>& nums, int i, int n, bool flag)
    {
        
        if(i == n - 1) //sirf ek element
            return 1;

        
        if(dp[i][flag] != -1)
            return dp[i][flag];
        int Take = 0;
        int notTake = 0;
        
        if(flag) 
        {
            
            if(nums[i + 1] > nums[i])  // include
            {
                 Take =  1 + helper(nums, i + 1, n, false);
            }
             notTake = helper(nums, i + 1, n, true);
            
        }
        else   
        {
            if(nums[i + 1] < nums[i])   // include
            {
                 Take = 1 + helper(nums, i + 1, n, true);
            }

                 notTake = helper(nums, i + 1, n, false);   
        }
        
        return dp[i][flag] = max(Take,notTake);
    }
    
    int wiggleMaxLength(vector<int>& nums) { 
        int n = nums.size();
        if(n==0)
            return 0;
        int ans = INT_MIN;
        memset(dp, -1, sizeof(dp));
        
        ans = max(ans, helper(nums, 0, n, true));
        
        memset(dp, -1, sizeof(dp));
        
        ans = max(ans, helper(nums, 0, n, false));
        
        return ans;
    }
};