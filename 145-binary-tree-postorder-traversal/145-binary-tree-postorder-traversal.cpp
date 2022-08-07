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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> S1;
        stack<TreeNode*> S2;
        vector<int> ans;
        S1.push(root);
        if(root==NULL)
            return ans;
        while(!S1.empty()){
            TreeNode* temp = S1.top();
            S1.pop();
            S2.push(temp);
            if(temp->left!=NULL)
                S1.push(temp->left);
            if(temp->right!=NULL)
                S1.push(temp->right);
        }
        while(!S2.empty()){
            ans.push_back(S2.top()->val);
            S2.pop();
        }
        return ans;
        
    }
};