class Solution {
public:
    #define ll long long
    int destroyTargets(vector<int>& nums, int space) {
        map<ll,ll> M;
        ll maxi=0;
        for(int i=0; i<nums.size(); i++){
            M[nums[i]%space]++;
            maxi = max(maxi,M[nums[i]%space]);
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