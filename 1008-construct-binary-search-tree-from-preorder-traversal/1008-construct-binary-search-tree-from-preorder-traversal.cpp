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
    TreeNode* soln(vector<int> & preorder, int ubound, int &i){
        if(i==preorder.size() || preorder[i]>ubound) return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left = soln(preorder, root->val, i);
        root->right = soln(preorder, ubound, i);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return soln(preorder, INT_MAX, i);
    }
};