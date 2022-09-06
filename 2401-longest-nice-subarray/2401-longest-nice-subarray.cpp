class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxi =1;
        int used = 0;
        int start = 0;
        for(int i=0; i<nums.size(); i++){
            while( (nums[i] & used)!=0){
                used = used ^ nums[start];
                start++;
            }
            used = used | nums[i];
            maxi = max (maxi, i-start+1);
        }
        return maxi;
    }
};