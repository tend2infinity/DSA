class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ngi(nums2.size(),0);
        vector<int> ans;
        stack<int> S;
        for(int i = nums2.size()-1; i>=0; i--){
            while(!S.empty() && S.top()<=nums2[i])
                S.pop();
            if(!S.empty()){
                ngi[i]=S.top();
            }
            else{
                ngi[i]=-1;
            }
            S.push(nums2[i]);
        }
        for(auto x: nums1){
           for(int i=0; i<nums2.size(); i++){
               if(x==nums2[i])
                   ans.push_back(ngi[i]);
           } 
        }
        return ans;
        
    }
};