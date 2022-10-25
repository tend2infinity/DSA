class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int num = n;
        vector<int> bin;
        while(num){
            bin.push_back(num%2);
            num = num/2;
        }
        // reverse(bin.begin(),bin.end());
        vector<long long> power;
        for(int i=0; i<bin.size(); i++){
            if(bin[i]) power.push_back( pow(2,i) );
        }
        vector<int> ans;
        for(auto x: queries){
            long long prod = 1;
            int l = x[0];
            int r = x[1];
            while(l<=r){
                prod = (prod% 1000000007) * (power[l] % 1000000007);
                l++;
            }
            ans.push_back(prod % 1000000007); 
        }
        return ans;
    }
};