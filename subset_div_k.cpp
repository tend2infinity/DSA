class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //approach 1 gives TLE
//         int total=0;
//         vector<int> subset_sum(nums.size()+1,0);
//         subset_sum[0] = 0;
//         for(int i=1;i<nums.size()+1;i++)
//             subset_sum[i] = nums[i-1]+subset_sum[i-1];
        
//         for(int i=1; i<nums.size()+1;i++){
//             vector<int>subset;
//             for(int j=i;j<nums.size()+1; j++){
//                 subset.push_back(nums[j-1]);
//                 int sum = subset_sum[j] - subset_sum[i-1];
//                 if(sum%k==0)
//                     total++;
//             }
//         }
//         return total;
        
        //approach 2
        int pref=0;
        int ans=0;
        vector<int>count_pref(k);
        count_pref[pref]++;
        for(int i=0; i<nums.size(); i++){
            pref=(pref+nums[i])%k;
            if(pref<0) pref= (pref+k)%k;
            ans=ans+count_pref[pref];
            count_pref[pref]++;
            
        }
        for(int i=0;i<k;i++)
            cout<<count_pref[i]<<" ";
        cout<<endl;
        return ans;
        
    }
};