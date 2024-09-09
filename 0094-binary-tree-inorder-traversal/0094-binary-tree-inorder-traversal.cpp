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
        if(root == NULL) return {};
        stack<TreeNode*> s;
        TreeNode* cur = root;
        vector<int> ans;
        while(!s.empty() || cur!=NULL){
            while(cur){
                s.push(cur);
                cur=cur->left;
            }
            cur = s.top();
            ans.push_back(cur->val);
            s.pop();
            cur=cur->right;
            
        }
        return ans;
    }
};