class Solution {
public:
//     int recur(int ind, vector<int>& dp1,vector<int>& dp2, vector<int>& nums ){
//         //base
//         if(ind==0){
//             return nums[0];
//         }
//         if(ind<0)
//             return 0;
//         if(dp[ind]!=-1)
//             return dp[ind];
        
//         maxProd= max(maxProd, maxProd*nums[ind]);
//         minProd = min(minProd, minProd*nums[ind]);
        
        

//         return dp[ind] = max(take,notTake); 

//     }
    int maxProduct(vector<int>& nums) {
        // vector<int>dp1(nums.size(),-1);
        // vector<int>dp2(nums.szie(),-1);
        // return recur(nums.size()-1,dp1,dp2,nums);
        
        if (nums.empty()) return 0;
		
        int best = INT_MIN;
        // Running products
        int maxProd = 1;
        int minProd = 1;
        
        for (int n: nums) {
            if (n < 0) 
                swap(maxProd, minProd);
            maxProd = max(maxProd*n, n);
            minProd = min(minProd*n, n);

            best = max(best, maxProd);
        }
        
        return best;
    }
};