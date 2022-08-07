class Solution {
public:
    int MOD = 1e9 + 7;
    int recur(int n, vector<int>& arr, int index, int prev, vector<vector<vector<int>>>& dp){
        //base
        if(n==0)
            return 1;
        if(index<0)
            return 0;
        if(dp[n][index][prev]!= -1)
            return dp[n][index][prev];
        
        int notTake = recur(n,arr,index-1,prev,dp);
        int Take = 0;

        
        if(prev==0){
            if(arr[index]==1)
                Take = recur(n-1,arr,4,1,dp)%MOD;
            else if(arr[index]==4)
                Take = recur(n-1,arr,4,4,dp)%MOD;

            else if(arr[index]==2)
                Take = recur(n-1,arr,4,2,dp)%MOD;
        }
        else if(prev==1){
            if(arr[index]==0)
                Take = recur(n-1,arr,4,0,dp)%MOD;
            else if(arr[index]==2)
                Take = recur(n-1,arr,4,2,dp)%MOD;
        }
        else if(prev==2){
            if(arr[index]==1)
                Take = recur(n-1,arr,4,1,dp)%MOD;
            else if(arr[index]==3)
                Take = recur(n-1,arr,4,3,dp)%MOD;
        }
        else if(prev==3){
            if(arr[index]==2)
                Take = recur(n-1,arr,4,2,dp)%MOD;
        }
        else if(prev==4){
            if(arr[index]==3)
                Take = recur(n-1,arr,4,3,dp)%MOD;
            else if(arr[index]==2)
                Take = recur(n-1,arr,4,2,dp)%MOD;
        }
        
        return dp[n][index][prev] = (notTake%MOD + Take%MOD)%MOD;     
        
        
    }
    
    int countVowelPermutation(int n) {
        vector<int> arr {0,1,2,3,4};
        long long int sum=0;
        vector<vector<vector<int>>> dp (n,vector<vector<int>>(5,vector<int>(5,-1)));
        for(auto i:arr){
            sum+=recur(n-1,arr,4,i,dp)%MOD;
        }
        return sum%MOD;
    }
};