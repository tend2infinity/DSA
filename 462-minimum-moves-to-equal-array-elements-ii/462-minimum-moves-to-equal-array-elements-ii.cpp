class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median,mid;
        if(nums.size()%2==0){
             mid = nums.size()/2;
             median = (nums[mid]+nums[mid-1])/2;
        }
        else{
            mid = nums.size()/2;
            median = nums[mid];
        }
        int moves=0;
        for(int i=0; i<nums.size(); i++){
            moves+= abs(nums[i]-median);
        }
        return moves;
        
    }
};