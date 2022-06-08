// https://leetcode.com/problems/regular-expression-matching/
//approach 1 
class Solution {
public:
    
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
                 recur(s.size(),s,p.size(),p,dp);   
                       int n= s.size();
        int m = p.size();
            for(int i=0;i<n+1;i++){
                for(int j=0; j<m+1; j++){
                cout<< dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[n][m];
    }
    bool recur(int i, string& s, int j, string &p, vector<vector<int>>& dp) {
        if(j==0)
            return i==0;
            
        if(p[j-1]=='*') {
            if(recur(i,s,j-2,p,dp) || 
               i>0 && (p[j-2] == '.' || s[i-1] == p[j-2]) && recur(i-1,s,j,p,dp)) 
			   return dp[i][j] = 1;
        } else if (i>0 && (p[j-1]=='.'|| s[i-1]==p[j-1]) && recur(i-1,s,j-1,p,dp)) 
			return dp[i][j] = 1;
        return dp[i][j] = 0;
    }
};


//approach 2
class Solution {
public:
    
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,0));
        int n= s.size();
        int m = p.size();
        dp[0][0] = 1;
        for(int i=1; i<n+1; i++)
            dp[i][0] = 0;
        // for(int j=2;j<m+1;j++){
        //     if(p[j-1]=='*')
        //         dp[0][j] = dp[0][j-2];
        // }
        for(int i=0; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(p[j-1]=='*'){
                    if( dp[i][j-2] || (i>0 && (p[j-2] == s[i-1] || p[j-2]=='.') && dp[i-1][j]) )
                        dp[i][j]=1;
                }
                else if ( i>0 && (p[j-1]=='.'||s[i-1]==p[j-1]) && dp[i-1][j-1] ) 
                    dp[i][j]=1;
                else dp[i][j]=0;
            }
        }
        for(int i=0;i<n+1;i++){
            for(int j=0; j<m+1; j++){
                cout<< dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[n][m];   
    }
    
    
//     bool recur(int i, string& s, int j, string &p, vector<vector<int>>& dp) {
//         if(j==0)
//             return i==0;
            
//         if(p[j-1]=='*') {
//             if(recur(i,s,j-2,p,dp) || 
//                i>0 && (p[j-2] == '.' || s[i-1] == p[j-2]) && recur(i-1,s,j,p,dp)) 
// 			   return dp[i][j] = 1;
//         } else if (i>0 && (p[j-1]=='.'|| s[i-1]==p[j-1]) && recur(i-1,s,j-1,p,dp)) 
// 			return dp[i][j] = 1;
//         return dp[i][j] = 0;
//     }
};