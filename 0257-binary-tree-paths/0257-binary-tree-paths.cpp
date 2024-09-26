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
    
    void soln(TreeNode* root, string k, vector<string> & ans){
        if(root == NULL) {
            return;
           
        }
        int t = root->val;
        k= k + "->" + to_string(t);
        if(!root->left && !root->right){
             k = k.substr(2, k.size()-2);
             ans.push_back(k);
            return;
        }
        soln(root->left, k, ans);
        soln(root->right, k,ans);
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        soln(root, "", ans);
        
        return ans;
    }
};