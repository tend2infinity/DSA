class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ngi(nums.size(),0);
        // vector<int> ans;
        stack<int> S;
        int n = nums.size();
        for(int i = 2*n-1; i>=0; i--){
            while(!S.empty() && S.top()<=nums[i%n])
                S.pop();
            if(i<n){
                if(!S.empty()){
                    ngi[i%n]=S.top();
                }
                else{
                    ngi[i%n]=-1;
                }                
            }
            S.push(nums[i%n]);
        }
        return ngi;
    }
};