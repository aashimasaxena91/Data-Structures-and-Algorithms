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
    int mx =INT_MIN;
    int ans(TreeNode* root){
        if(root==NULL) return 0;
        int lh = max(0,ans(root->left));
        int rh = max(0,ans(root->right));
        mx = max(mx, lh+rh+root->val);
        return max(lh,rh)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        
        ans(root);
        return mx;
       
    }
};