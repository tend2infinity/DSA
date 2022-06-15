class Solution {
public:
    int recur(int i, int j, vector<vector<int>> & dp){
        //base
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int up = recur(i-1,j,dp);
        int left = recur(i,j-1,dp);
        return dp[i][j] = left + up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return recur(m-1,n-1,dp);
    }
};