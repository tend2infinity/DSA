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
    TreeNode* recur(vector<int>& preOrder, int preStart, int preEnd, vector<int>& inOrder, int inStart, int inEnd, unordered_map<int,int>& M ){
        
        if(inStart>inEnd || preStart>preEnd)
            return NULL;
        TreeNode* root = new TreeNode(preOrder[preStart]);
        int inRoot = M[root->val];
        int inLeft = inRoot - inStart;
        
        root -> left = recur(preOrder, preStart+1, preStart+inLeft, inOrder, inStart, inRoot-1,M);
        root -> right = recur(preOrder, preStart+1+inLeft, preEnd, inOrder, inRoot+1, inEnd,M );
        return root;
        
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map <int,int> M;
        for(int i=0; i<inorder.size(); i++){
            M[inorder[i]]=i;
        }    
        return recur(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, M);
    }
};