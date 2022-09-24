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
    vector<int> dup;
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<vector<int>> ans;
        Q.push(root);
        vector<int> curr;
        if(root ==NULL)
            return ans;
        while(!Q.empty()){
            int n = Q.size();
            for(int i=0; i<n; i++){ 
                TreeNode* temp = Q.front();
                Q.pop();
                curr.push_back(temp->val);
                if(temp->left!=NULL)
                    Q.push(temp->left);
                if(temp->right!= NULL)
                    Q.push(temp->right);                    
            }
            ans.push_back(curr);
            curr = dup;
        }
        return ans;
    }
};