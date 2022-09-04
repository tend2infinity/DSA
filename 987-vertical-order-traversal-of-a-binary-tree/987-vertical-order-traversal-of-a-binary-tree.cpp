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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> Q;
        Q.push({root,{0,0}});
        while(!Q.empty()){
            auto itr = Q.front();
            Q.pop();
            TreeNode* Node = itr.first;
            int x = itr.second.first;
            int y = itr.second.second;
            nodes[x][y].insert(Node->val);
            if(Node->left)
            Q.push({Node->left,{x-1,y+1}});
            if(Node->right)
            Q.push({Node->right,{x+1,y+1}});
        }
        
        for(auto a:nodes){
            vector<int> level;
            for(auto b :a.second){
                level.insert(level.end(),b.second.begin(),b.second.end());
            }
            ans.push_back(level);
        }
        return ans;   
        } 
};