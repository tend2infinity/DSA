class Solution {
public:
    int count_zero(string &str){
        int count=0;
        for(int i=0; i<str.size(); i++){
            if(str[i]=='0')
                count++;
        }
        return count;
    }

    int recur(int i,vector<string>& strs, int m, int n,vector<vector<vector<int>>>& dp ){
        //base
        if(i<0 || (m<=0 && n<=0))
            return 0;

       if(dp[i][m][n]!= -1)
           return dp[i][m][n] ; 
        
        int notPick = recur(i-1,strs,m,n,dp);
        int Pick=0;
        int curr_zero = count_zero(strs[i]);
        int curr_one = strs[i].size() - curr_zero;
        if(curr_zero<=m&& curr_one<=n ){
            Pick = 1 + recur(i-1,strs,m-curr_zero,n-curr_one,dp);
        }
        
        return dp[i][m][n] = max(Pick,notPick);
            
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int zero=0;
        int one=0;
        vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return recur(strs.size()-1,strs,m,n,dp);
    }
};

//appraoch 2
class Solution {
public:
    int count_zero(string &str){
        int count=0;
        for(int i=0; i<str.size(); i++){
            if(str[i]=='0')
                count++;
        }
        return count;
    }

    int recur(int i,vector<string>& strs, int m, int n,vector<vector<vector<int>>>& dp ){
        //base
        if(i<0 || (m==0 && n==0))
            return 0;

       if(dp[i][m][n]!= -1)
           return dp[i][m][n] ; 
        
        int notPick = recur(i-1,strs,m,n,dp);
        int Pick=0;
        int curr_zero = count_zero(strs[i]);
        int curr_one = strs[i].size() - curr_zero;
        if(curr_zero<=m&& curr_one<=n ){
            Pick = 1 + recur(i-1,strs,m-curr_zero,n-curr_one,dp);
        }
        
        return dp[i][m][n] = max(Pick,notPick);
            
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int zero=0;
        int one=0;
        vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        // return recur(strs.size()-1,strs,m,n,dp);
        
        for(int i=0;i<=m; i++){
            for(int j=0; j<=n; j++){
                dp[0][i][j] = 0;
            }
        }
        for(int i=1;i<=strs.size();i++)
            dp[i][0][0] = 0;
        
        for(int i=1; i<=strs.size(); i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    int notPick = dp[i-1][j][k];
                    int Pick=0;
                    int curr_zero = count_zero(strs[i-1]);
                    int curr_one = strs[i-1].size() - curr_zero;
                    if(curr_zero<=j&& curr_one<=k ){
                        Pick = 1 + dp[i-1][j-curr_zero][k-curr_one];
                    }

                     dp[i][j][k] = max(Pick,notPick);
                }
            }
        }
        return dp[strs.size()][m][n];
    }
};

//apprach 3
class Solution {
public:
    int count_zero(string &str){
        int count=0;
        for(int i=0; i<str.size(); i++){
            if(str[i]=='0')
                count++;
        }
        return count;
    }

    int recur(int i,vector<string>& strs, int m, int n,vector<vector<vector<int>>>& dp ){
        //base
        if(i<0 || (m==0 && n==0))
            return 0;

       if(dp[i][m][n]!= -1)
           return dp[i][m][n] ; 
        
        int notPick = recur(i-1,strs,m,n,dp);
        int Pick=0;
        int curr_zero = count_zero(strs[i]);
        int curr_one = strs[i].size() - curr_zero;
        if(curr_zero<=m&& curr_one<=n ){
            Pick = 1 + recur(i-1,strs,m-curr_zero,n-curr_one,dp);
        }
        
        return dp[i][m][n] = max(Pick,notPick);
            
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int zero=0;
        int one=0;
        // vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        // return recur(strs.size()-1,strs,m,n,dp);

        vector<vector<int>> prev(m+1,(vector<int>(n+1,0)));
        for(int i=0;i<=m; i++){
            for(int j=0; j<=n; j++){
                prev[i][j] = 0;
            }
        }
        // for(int i=1;i<=strs.size();i++)
        //     dp[i][0][0] = 0;
        
        for(int i=1; i<=strs.size(); i++){
        vector<vector<int>> curr(m+1,(vector<int>(n+1,0)));
            curr[0][0]=0;
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    int notPick = prev[j][k];
                    int Pick=0;
                    int curr_zero = count_zero(strs[i-1]);
                    int curr_one = strs[i-1].size() - curr_zero;
                    if(curr_zero<=j&& curr_one<=k ){
                        Pick = 1 + prev[j-curr_zero][k-curr_one];
                    }

                     curr[j][k] = max(Pick,notPick);
                }
            }
            prev = curr;
        }
        return prev[m][n];
    }
};