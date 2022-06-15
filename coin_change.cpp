class Solution {
public:
    int recur(vector<int>& coins, int target, int index, vector<vector<int>>& dp){
        //base
        if(target==0)
        return 0;
        // if(index==0){
        //     if(coins[index]<=target && target%coins[index]==0)
        //         return target/coins[index];
        //     else
        //         return -1;
        // }
        if(index<0)
            return 1e8;
        if(dp[index][target]!= -1)
            return dp[index][target];

        
        int notTake = recur(coins,target,index-1,dp);
        int Take = 1e8;
        if(target>=coins[index])
            Take = 1 + recur(coins,target-coins[index], index,dp);
        
        return dp[index][target] = min(Take,notTake);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        sort(coins.begin(),coins.end());
        int ans = recur(coins,amount,coins.size()-1,dp);
        if(ans>=1e8)
            return -1;
        else return ans;
    }
};