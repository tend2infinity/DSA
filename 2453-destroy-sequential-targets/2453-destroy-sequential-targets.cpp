class Solution {
public:
    #define ll long long
    int destroyTargets(vector<int>& nums, int space) {
        map<ll,ll> M;
        for(int i=0; i<nums.size(); i++){
            M[nums[i]%space]++;
        }
        long long maxi = 0;
        for(auto m:M){
            maxi= max(maxi,m.second);
        }
        vector<ll> V1;
        for(auto m:M){
            if(m.second==maxi)
                V1.push_back(m.first);
        }
        int mini = INT_MAX;
        for(auto x:nums){
            if( find(V1.begin(),V1.end(),x%space) != V1.end()){
                mini = min(mini,x);
            }
        }
        return mini;
    }
};