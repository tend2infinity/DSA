class Solution {
public:
    int recur(vector<int>& cost,int index, vector<int>& dp){
        //base
        if(index == cost.size()-1)
            return cost[cost.size()-1];
        if(index> cost.size()-1)
            return 0;
        if(dp[index]!= -1)
            return dp[index];
        
        int one = cost[index] + recur(cost, index+1,dp);
        int two = cost[index] + recur(cost, index+2,dp);
        return dp[index] = min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp1(cost.size()+1,-1);
        int one = recur(cost,0,dp1);
        vector<int> dp2(cost.size()+1,-1);
        int two = recur(cost,1,dp2);
        return min(one,two);
    }
};