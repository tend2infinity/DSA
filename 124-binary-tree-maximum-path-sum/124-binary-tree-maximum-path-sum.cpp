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
    int height(TreeNode* root, int& sum, set<int>& S){
        if(root == NULL)
            return 0;
        S.insert(root->val);
        int lh = max(0,height(root->left,sum,S));
        int rh = max(0,height(root->right,sum,S));
        sum = max(sum,root->val+lh+rh);
        return root->val + max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        int sum=root->val;
        set<int> S;
        height(root,sum,S);
        if(*S.rbegin()<0)
            return *S.rbegin();
        return sum;
    }
};