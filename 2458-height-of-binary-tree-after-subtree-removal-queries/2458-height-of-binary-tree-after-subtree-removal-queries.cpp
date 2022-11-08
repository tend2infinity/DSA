/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,int> height;
    map<int,int> depth;
    map<int,vector<pair<int,int>>> cousin; // at a particular depth what are its cousin heights;
    
    int dfs(TreeNode* root, int level){
        if(root==NULL) return -1;
        depth[root->val]=level;
        int lh = dfs(root->left,level+1);
        int rh = dfs(root->right,level+1);
        height[root->val] = 1+max(lh,rh);
        return height[root->val];
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int max_height = dfs(root,0);
        vector<int> ans;
        for(auto d: depth){
            cousin[d.second].push_back({height[d.first],d.first});
            sort(cousin[d.second].begin(),cousin[d.second].end(),greater<pair<int,int>>());
            if(cousin[d.second].size()>2) cousin[d.second].pop_back();
        }
        
        for(auto q: queries){
            int d = depth[q];
            if(cousin[d].size()==1)
                ans.push_back(d-1);
            else if(cousin[d][0].second==q)
                ans.push_back(cousin[d][1].first + d);
            else
                ans.push_back(max_height);
        }
        return ans;
    }
};