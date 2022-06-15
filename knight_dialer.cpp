#define ll long long int
class Solution {
public:
    long long int recur(int i, int j, vector<vector<int>>& grid,int jumps,int row,int column,vector<vector<vector<long long int>>> &dp){
        //base
        if(i<0 || i>row || j<0 || j>column || grid[i][j]==10 || grid[i][j]==11 || jumps<0)
            return 0;
        if(jumps==0)
            return 1;
        if(dp[i][j][jumps]!=-1)
            return dp[i][j][jumps];
        
        ll left_up = recur(i-1,j-2,grid,jumps-1,row,column,dp)  % (long long int)(1e9 +7);
        ll left_down = recur(i+1,j-2,grid,jumps-1,row,column,dp) % (long long int)(1e9 +7);
        ll right_up = recur(i-1,j+2,grid,jumps-1,row,column,dp) % (long long int)(1e9 +7);
        ll right_down = recur(i+1,j+2,grid,jumps-1,row,column,dp) % (long long int)(1e9 +7);
        ll up_left = recur(i-2,j-1,grid,jumps-1,row,column,dp) % (long long int)(1e9 +7);
        ll up_right = recur(i-2,j+1,grid,jumps-1,row,column,dp) % (long long int)(1e9 +7);
        ll down_left = recur(i+2,j-1,grid,jumps-1,row,column,dp) % (long long int)(1e9 +7);
        ll down_right = recur(i+2,j+1,grid,jumps-1,row,column,dp) % (long long int)(1e9 +7);
        
        return dp[i][j][jumps] = left_up + left_down + right_up + right_down + up_left + up_right + down_left + down_right;
    }
    int knightDialer(int n) {
        vector<vector<int>>grid{{1,2,3},{4,5,6},{7,8,9},{10,0,11}};
        vector<vector<vector<ll>>>dp(4,vector<vector<ll>>(3,vector<ll>(n,-1)));
        long long int count=0;
        for(int i=0; i<=3; i++){
            for(int j=0; j<=2; j++){
                 count += (recur(i,j,grid,n-1,3,2,dp) % (long long int)(1e9 +7));
            }  
        }
        return count % (long long int)(1e9 +7);
    }
};