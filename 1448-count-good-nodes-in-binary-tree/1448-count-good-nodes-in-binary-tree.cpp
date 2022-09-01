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
    int util(int max, TreeNode* node){
        if(node==NULL)  return 0;
        
        if(node->val >= max){
            return 1 + util(node->val, node->left) + util(node->val, node->right);
        }
        else{
            return util(max, node->left) + util(max, node->right);
        }
        
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)  return 0;
        
        return util(root->val, root);
    }
};