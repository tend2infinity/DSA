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

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack <TreeNode*>S;
        TreeNode* temp = root;
        while(true){
            if(temp!=NULL){
                S.push(temp);
                temp = temp->left;
            }
            else{
                if(S.empty())
                    break;
                temp = S.top();
                S.pop();
                ans.push_back(temp->val);
                temp = temp -> right;
            }
        }
        return ans;
    }
};