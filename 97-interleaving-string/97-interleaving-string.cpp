class Solution {
public:
bool recur(string& s1, string& s2, string& s3, int i, int j, int k, vector<vector<vector<int>>>& dp ){
        //base
        if(i==s1.size() && j==s2.size() && k==s3.size())
            return true;
        if( ( i<s1.size() || j<s2.size() ) && k==s3.size())
            return false;
        if( i==s1.size() && j==s2.size() && k<s3.size())
            return false;
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        if(k<s3.size()){
            
            if(i<s1.size() && j<s2.size() && s1[i] == s3[k] && s2[j] == s3[k]){
                return dp[i][j][k] =  recur(s1,s2,s3,i+1,j,k+1,dp) || recur(s1,s2,s3,i,j+1,k+1,dp);
            }

            if(i<s1.size() && s1[i] == s3[k])
                return dp[i][j][k] = recur(s1,s2,s3,i+1,j,k+1,dp);
            if(j<s2.size() && s2[j] == s3[k])
                return dp[i][j][k] = recur(s1,s2,s3,i,j+1,k+1,dp);
            
        }

        
        return dp[i][j][k] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>> dp(s1.size()+1,vector<vector<int>>(s2.size()+1, vector<int>(s3.size()+1,-1)));
        return recur(s1,s2,s3,0,0,0,dp);
    }
    
};