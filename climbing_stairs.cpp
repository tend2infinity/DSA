class Solution {
public:
    int recur(int index, vector<int>& dp){
        //base
        if(index==0)
            return 1;
        if(index<0)
            return 0;
        if(index==1)
            return 1;
        if(dp[index]!=-1)
            return dp[index];
        int one = recur(index-1,dp);
        int two = recur(index-2,dp);
        return dp[index] = one + two;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return recur(n,dp);    
    }
};