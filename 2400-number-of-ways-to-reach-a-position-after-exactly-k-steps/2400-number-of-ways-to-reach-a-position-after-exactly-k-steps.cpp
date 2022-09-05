class Solution {
public:
    int dp[3020][1005];
int numberOfWays(int s, int e, int k) {
    memset(dp,-1,sizeof dp);
    return ways(s,e,k);
}

int ways(int s,int e,int k){
    if(s==e && k==0) return 1;
    if(k==0) return 0;
    if(dp[s+1000][k]!=-1) return dp[s+1000][k];
    return dp[s+1000][k] = (ways(s-1,e,k-1) + ways(s+1,e,k-1))%1000000007;
} 
};