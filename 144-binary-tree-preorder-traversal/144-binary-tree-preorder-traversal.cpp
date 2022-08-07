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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> S;
        S.push(root);
        if(root == NULL)
            return ans;
        while(!S.empty()){
            TreeNode* temp = S.top();
            S.pop();
            ans.push_back(temp -> val);
            if(temp->right!=NULL)
                S.push(temp->right);
            if(temp->left!=NULL)
               S.push(temp->left);
        }
        return ans;
    }
};