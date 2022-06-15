class Solution {
public:
    int recur(string & s, int index, vector<int>& dp){
        //base

        if(index<0)
            return 1;
        if(dp[index]!= -1)
            return dp[index];
        
        int Take_1 = 0;
        if( (s[index] - '0') >=1)
            Take_1+=recur(s,index-1,dp);
        int Take_2 = 0;
        if( index>=1){
            string str="";    
            str.push_back(s[index-1]);
            str.push_back(s[index]);
            if(stoi(str)<=26 && stoi(str)>=10)
                Take_2+=recur(s,index-2,dp);  
            } 
        return dp[index] = Take_1 + Take_2;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size()+1,-1);
        return recur(s,s.size()-1,dp);
    }
};