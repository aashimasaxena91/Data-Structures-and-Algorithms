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
class NODE {
    public:
    int sz, low, high;
    NODE(int x, int y, int z) : sz(x), low(y), high(z) {}
};
class Solution {
public:
    NODE helper(TreeNode* root){
        if(!root) return  NODE(0, INT_MAX, INT_MIN);
        auto a = helper(root->left);
        auto b = helper(root->right);
        
        if(a.high<root->val && b.low>root->val){
            return  NODE((1+a.sz + b.sz), min(a.low, root->val), max(b.high, root->val));
        }
        
        return  NODE(max(a.sz,b.sz), INT_MIN, INT_MAX);
    }
    
    
    int largestBSTSubtree(TreeNode* root) {
        return helper(root).sz;
    }
};