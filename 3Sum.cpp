class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int> > res;

    std::sort(nums.begin(), nums.end());
        
    for (int i = 0; i < nums.size(); i++) {
        
        int target = -nums[i];
        int front = i + 1;
        int back = nums.size() - 1;

        while (front < back) {

            int sum = nums[front] + nums[back];

            if (sum < target)
                front++;
            else if (sum > target)
                back--;

            else {
                vector<int> triplet = {nums[i], nums[front], nums[back]};
                res.push_back(triplet);

                while (front < back && nums[front] == triplet[1]) front++;

                while (front < back && nums[back] == triplet[2]) back--;
            }
            
        }

        // Processing duplicates of Number 1
        while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
            i++;

    }
    
    return res;
    }
};

//approach 2

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int> > res;
        sort(nums.begin(),nums.end());
        if(nums.size()<3)
            return res;
        if(nums[0]>0)
            return res;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]=i;
        }
        for(int i=0; i<nums.size()-2; i++){
            int first = nums[i];
            if(first>0)
                break;
            for(int j=i+1;j<nums.size()-1;j++){
                int second=nums[j];
                int third = -(first + second);
                if(mp.find(third)!=mp.end() && mp.find(third)->second>j){
                    vector<int> triplet;
                    triplet.push_back(first);
                    triplet.push_back(second);
                    triplet.push_back(third);
                    res.push_back(triplet);
                }
                j=mp[nums[j]]; //avoid duplicate
            }
            i=mp[nums[i]]; //avoid duplicate
        }
    
    return res;
    }
};