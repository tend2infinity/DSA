class Solution {
public:
    
    int dp[1005][2];
    
//     int helper(vector<int>& nums, int i, int n, bool flag)
//     {
        
//         if(i == n - 1) //sirf ek element
//             return 1;

        
//         if(dp[i][flag] != -1)
//             return dp[i][flag];
        
//         int ans = 0;
        
//         if(flag) 
//         {
//             if(nums[i + 1] > nums[i])  // include
//             {
//                 ans = max(ans, 1 + helper(nums, i + 1, n, false));
//             }
//             else  // exclude
//             {
//                 ans = max(ans, helper(nums, i + 1, n, true));
//             }
//         }
//         else   
//         {
//             if(nums[i + 1] < nums[i])   // include
//             {
//                 ans = max(ans, 1 + helper(nums, i + 1, n, true));
//             }
//             else  // exclude
//             {
//                 ans = max(ans, helper(nums, i + 1, n, false));
//             }
//         }
        
//         return dp[i][flag] = ans;
//     }
    
    int wiggleMaxLength(vector<int>& nums) { 
        int n = nums.size();
        if(n==0)
            return 0;
        int ans = INT_MIN;
        memset(dp, 0, sizeof(dp));
        dp[n-1][0] = 1;
        dp[n-1][1] = 1;
        
        for(int i=n-2; i>=0; i--) {
            for(int flag=0; flag<=1; flag++){
                int ans = 0;
                if(flag==1) 
                {
                    if(nums[i + 1] > nums[i])  // include
                    {
                        ans = max(ans, 1 + dp[i + 1][0]);
                    }
                    else  // exclude
                    {
                        ans = max(ans, dp[i + 1][1]);
                    }
                }
                else   
                {
                    if(nums[i + 1] < nums[i])   // include
                    {
                        ans = max(ans, 1 + dp[i + 1][1]);
                    }
                    else  // exclude
                    {
                        ans = max(ans, dp[i + 1][0]);
                    }
                }
                dp[i][flag] = ans;
            }
        }
        
        
        return max(dp[0][0],dp[0][1]);
    }
};