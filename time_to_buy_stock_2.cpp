class Solution {
public:
    int recur(int index,int buy,vector<int>& prices, vector<vector<int>>& dp ){
        //base
        if(index==prices.size())
            return 0;
        if(dp[index][buy]!= -1)
            return dp[index][buy];
        
        if(buy==1){
            int profit = -prices[index] + recur(index+1,0,prices,dp);
            int no_profit = recur(index+1,1,prices,dp);
            return dp[index][buy] = max(profit,no_profit);
        }
        else{
            int profit = +prices[index] + recur(index+1,1,prices,dp);
            int no_profit = recur(index+1,0,prices,dp);
            return dp[index][buy] = max(profit,no_profit);
        }
 
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]= 0;
        dp[n][1]=0;
        for(int index=n-1; index>=0; index--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    int profit = -prices[index] + dp[index+1][0];
                    int no_profit = dp[index+1][1];
                     dp[index][buy] = max(profit,no_profit);
                }
                else if(buy==0){
                    int profit = +prices[index] + dp[index+1][1];
                    int no_profit = dp[index+1][0];
                     dp[index][buy] = max(profit,no_profit);
                }
            }
        }
        return dp[0][1];
        // return recur(0,1,prices,dp);
    }
};