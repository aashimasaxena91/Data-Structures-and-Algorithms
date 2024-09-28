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
    
    void inorder(vector<int>& ans, TreeNode* root){
        if(!root) return;
        while(root){
            if(root->left==NULL){
                ans.push_back(root->val);
                root=root->right;
            }else{
                TreeNode* prev = root->left;
                while(prev->right && prev->right!=root){
                    prev = prev->right;
                }
                if(prev->right==NULL){
                    prev->right = root;
                    root=root->left;
                }else{
                    prev->right = NULL;
                    ans.push_back(root->val);
                    root=root->right;
                }
            }
        }
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(ans, root);
        int l = 0, r = ans.size()-1;
        while(l<r){
            if(ans[l]+ans[r]==k){
                return true;
            }else if(ans[l]+ans[r]<k)
                l++;
            else
                r--;
        }
        return false;
    }
};