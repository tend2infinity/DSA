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

        int mini = INT_MAX;
        for(auto x:nums){
            if(M[x%space]==maxi){
                mini = min(mini,x);
            }
        }
        return mini;
    }
};