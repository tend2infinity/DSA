class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        if(nums.empty())
            return ans;
        if(nums.size()<4)
            return ans;
        for(int i=0; i<nums.size(); i++){
            int first = nums[i];
            for(int j=i+1; j<nums.size(); j++){
                int second = nums[j];
                int goal = target - first - second;
                int l=j+1;
                int r=nums.size()-1;
                while(l<r){
                    if(nums[l]+nums[r] < goal)
                        l++;
                    else if(nums[l]+nums[r]>goal)
                        r--;
                    else{
                        vector<int>quad;
                        quad.push_back(first);
                        quad.push_back(second);
                        quad.push_back(nums[l]);
                        quad.push_back(nums[r]);
                        ans.push_back(quad);
                        int last_l = nums[l];
                        int last_r = nums[r];
                        while(l<r && nums[l] == last_l)
                            l++;
                        while(l<r && nums[r] == last_r)
                            r--;
                    }

                }
                while(j+1<nums.size() && nums[j] == nums[j+1])
                    j++;
            }
            while(i+1<nums.size() && nums[i] == nums[i+1])
                i++;
        }
        return ans;
    }
};