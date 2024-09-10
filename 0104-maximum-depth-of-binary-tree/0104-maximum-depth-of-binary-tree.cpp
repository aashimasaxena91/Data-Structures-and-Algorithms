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
    int ans(TreeNode* root, int res, int depth){
        if(root==NULL) return depth;
        if(depth==res) res++;
       depth= max( ans(root->left, res, depth+1), ans(root->right, res, depth+1));
        return depth;
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return ans(root, 0, 0);
    }
};