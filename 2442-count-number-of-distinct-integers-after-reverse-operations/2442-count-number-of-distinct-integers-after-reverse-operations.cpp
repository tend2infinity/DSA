class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int s = nums.size();
        map <int,int> M;
        string S;
        for(int i=0; i<s;i++)
            M[nums[i]]++;
        
        
        for(int i=0; i<s; i++){
            S = to_string(nums[i]);
            int size = S.size();
            for(int i=0; i<size/2; i++){
                swap(S[i],S[size-1-i]);
            }
            M[stoi(S)]++;
            // if(M[stoi(S)]==0)
            //     ans++;
            S.clear();
        }
        int ans = M.size();
        return ans;
    }
};