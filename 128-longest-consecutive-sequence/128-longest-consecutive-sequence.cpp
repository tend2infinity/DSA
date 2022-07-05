class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i:nums){
            map[i]++;
        }
        int maxStreak = 0;;
        for(int i: nums){
            if(map.find(i-1)==map.end()){
                int current = i;
                int currStreak=1;
                while(map.find(current+1)!= map.end()){
                    current++;
                    currStreak++;
                }
                maxStreak = max(maxStreak,currStreak);
            }
        }
        return maxStreak;
        
    }
};