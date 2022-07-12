class Solution {
public:
//     int recur( vector<int>& nums, int k, int index, vector<int>& dp){
//         //base
//         if(index == nums.size()-1)
//             return nums[nums.size()-1];
//         if(index > nums.size()-1)
//             return -1e8;
//         if(dp[index] != -1)
//             return dp[index];

//         int val = nums[index];
//         int i = 1;
//         int maxi = -1e8;
//         int size = nums.size()-1;
//         while( i<= min(k,size)){
//             maxi = max(maxi, val+ recur(nums,k,index+i,dp));
//             i++;
//         }
//        return dp[index] =  maxi;
        
//     }
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size()+1, 0);
        int size = nums.size()-1;
        dp[size] = nums[size];
        multiset <int,greater<int>> S = {dp[size]};
        for(int index = size-1; index>=0; index--){               //jumping backwards
            if(index < size-k)
                S.erase(S.find(dp[index+k+1]));
            S.insert(dp[index] = nums[index] + *S.begin()); 
        }   
       return dp[0];
    }
};