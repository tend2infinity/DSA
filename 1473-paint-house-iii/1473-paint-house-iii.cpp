class Solution {
public:
    int dp[101][101][21];
    int recur(vector<int>& houses, vector<vector<int>>& cost, int target, int index, int groups, int prev ){
        //base
        if(index<0){
            if(groups == target)
                return 0;
            else return 1e8;
        }
        
        if(groups >target)
            return 1e8;
        
        if(dp[index][groups][prev]!= -1)
            return dp[index][groups][prev];
        
        int mini = 1e8; 
        int n = cost[0].size();
        
        if(houses[index] == 0){
            for(int i=1; i<=n; i++){
                if(prev == i)
                mini = min(mini, cost[index][i-1] + recur(houses,cost,target,index-1,groups,i));
                else
                mini = min(mini, cost[index][i-1] + recur(houses,cost,target,index-1,groups+1,i));
            }
        }
        else{
            if(prev == houses[index])
                mini = min(mini, recur(houses,cost,target,index-1,groups,houses[index]) );
            else
                mini = min(mini,recur(houses,cost,target,index-1,groups+1,houses[index]) ) ;
        }
        return dp[index][groups][prev] = mini;
        
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof(dp));
        int ans = recur(houses,cost,target, houses.size()-1,0,0);
        if(ans == 1e8)
            return -1;
        else
            return ans;
    }
};