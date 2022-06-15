class Solution
{
    public:
    
    int recur(int target, vector<int>& len, int index,vector<vector<int>>& dp){
    //base
    if(index<0)
    return -1e8;     
    if(target==0)
    return 0;
    
    if(dp[target][index] != -1)
        return dp[target][index];
        
    int notTake = recur(target,len,index-1,dp);
    int take = -1e8;
    if(target >=len[index])
        take = 1 + recur(target-len[index],len,index,dp);
        
    return dp[target][index] =  max(take,notTake);
    }


    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> len{x,y,z};
        sort(len.begin(),len.end());
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        recur(n,len,2,dp);
        // for(int i=0; i<=n; i++){
        //     for(int j=0; j<=2; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        if(dp[n][2]<0)
            return 0;
        return dp[n][2];
    }
};