class Solution {
public:
    vector<int> nodes;
    vector<vector<int>> list;
    int checkDFS(int curr, int parent, int target){
        int val = nodes[curr];
        for(auto x: list[curr]){
            if(x!=parent) val+=checkDFS(x,curr,target);
        }
        if(val == target)
            return 0;
        return val;
    }
    
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        nodes.empty();
        list.empty();
        int n = nums.size();
        int maxi=0;
        nodes.resize(n);
        list.resize(n);
        int sum=0;
        for(auto edge : edges){
            list[edge[0]].push_back(edge[1]);
            list[edge[1]].push_back(edge[0]);
        }
        for(int i=0; i<n; i++){
            sum+=nums[i];
            nodes[i] = nums[i];
        }
        
        for(int i=1; i<=n; i++){
            if(sum%i !=0 ) continue;
            if(checkDFS(0,-1,sum/i) == 0 ){
                maxi = max(maxi,i-1);
            }
        }
        return maxi;
        
    }
};