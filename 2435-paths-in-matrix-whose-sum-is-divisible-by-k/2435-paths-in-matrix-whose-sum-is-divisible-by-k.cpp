class Solution {
public:
    int recur(int i, int j,int m, int n,vector<vector<int>>& grid, int k, int sum,vector<vector<vector<int>>>& dp){
        //base
        if(i>=m || j>=n )
            return 0;
        if(i==m-1 && j==n-1){
            sum+=grid[i][j];
            // cout<<sum<<endl;
            if(sum % k ==0){
                return 1;
            }
            return 0;
        }  
        sum+=grid[i][j];
        
        if(dp[i][j][sum%k]!= -1)
            return dp[i][j][sum%k];

        int right = recur(i,j+1,m,n,grid,k,sum,dp);
        int down = recur(i+1,j,m,n,grid,k,sum,dp);
        
        return dp[i][j][sum%k] = (right% 1000000007 + down % 1000000007) % 1000000007;    

    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>>dp (m,vector<vector<int>>(n,vector<int>(k,-1)));
        int ans = recur(0,0,m,n,grid,k,0,dp);
        return ans;
    }
};