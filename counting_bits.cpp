class Solution {
public:
    int findBinary(int n, vector<int>& dp){
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(dp[n]!= -1)
            return dp[n];
        if(n%2 == 0) return dp[n] = findBinary(n/2,dp);
        else return dp[n]= 1+ findBinary((n-1)/2,dp);
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        vector<int> dp(n+1,-1);
        for(int i=0; i<=n; i++){
            ans[i] = findBinary(i,dp);
        }
        return ans;
    }
};