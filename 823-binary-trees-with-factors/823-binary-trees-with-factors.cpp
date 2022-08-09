class Solution {
    int mod = 1e9 + 7;
    unordered_map<int, long long int> dp;
    unordered_set<int> st;
private:
    long long int factorCount(int root)
    {

        if(dp.count(root))
            return dp[root];
        
        long long int count = 1;

        for(auto &val : st)
        {

            if(root % val != 0) continue;
            
            int factor1 = val, factor2 = root / val;
            
            if(st.count(factor2))
            {
                count += factorCount(factor1) * factorCount(factor2);
                count %= mod;
            }
            
         }
        
        return dp[root] = count;
    }
    
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
                
        st.insert(arr.begin(), arr.end());
        
        int res = 0;
        
        for(auto &curVal : arr)
        {
            res += factorCount(curVal);
            res %= mod;
        }
        
        return res;
    }
};