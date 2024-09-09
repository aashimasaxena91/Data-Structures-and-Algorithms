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
    void soln(TreeNode* root, int depth, vector<vector<int>> & ans ){
        if(root == NULL) return ;
        if(depth == ans.size()) ans.push_back(  vector<int> ());
        ans[depth].push_back(root->val);
        soln(root->left, depth+1, ans);
        soln(root->right, depth+1, ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        soln(root, 0, ans);
        return ans;
    }
};