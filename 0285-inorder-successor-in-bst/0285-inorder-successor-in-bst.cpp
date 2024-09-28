/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ans = new TreeNode(INT_MAX);
        while(root){
            if(root->val<=p->val){
                root=root->right;
            }else{
                ans->val = min(ans->val, root->val);
                root = root->left;
            }
        }
        if(ans->val == INT_MAX) return NULL;
        return ans;
    }
};