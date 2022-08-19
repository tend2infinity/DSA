class Solution {
public:
    vector<int> vec;
    bool isPossible(vector<int>& nums) {
        map <int,int> freq;
        map <int,int> need;
        for(auto num: nums){
            freq[num]++;
        }
        for(int i=0; i<nums.size(); i++){
            if(freq[nums[i]]==0)
                continue;
            if(need[nums[i]]){
                freq[nums[i]]--;
                need[nums[i]]--;
                need[nums[i]+1]++;
            }
            else if(freq[nums[i]]>0 && freq[nums[i]+1]>0 && freq[nums[i]+2]>0){
                cout<<i<<endl;
                freq[nums[i]]--;
                freq[nums[i]+1]--;
                freq[nums[i]+2]--;
                need[nums[i]+3]++;
            }
            else{
                return false;
            }
        }
    return true;
    }

};