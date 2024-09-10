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
    
    int ans(TreeNode* root){
        if(root ==NULL) return 0;
        int l = ans(root->left);
        if(l==-1) return -1;
        int r = ans(root->right);
         if(r==-1) return -1;
        int height = abs(l-r);
        if(height>1) return -1;
        else return 1+max(l,r);
    }
    
    bool isBalanced(TreeNode* root) {
        if(root ==NULL) return true;
        if(ans(root)==-1) return false;
        return true;
    }
};