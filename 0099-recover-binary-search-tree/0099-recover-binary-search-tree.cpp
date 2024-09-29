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
    void trav(TreeNode* root, vector<int> & inorder){
        if(!root) return;
       
        trav(root->left, inorder);
          inorder.push_back(root->val);

        trav(root->right, inorder);
    }
    void trav2(TreeNode* root, vector<int> & inorder, int &i){
         if(!root || i>=inorder.size()) return;
        
        trav2(root->left, inorder, i);
       
         if(root->val!= inorder[i]) root->val = inorder[i];
 i++;
        trav2(root->right, inorder, i);
    }
    void recoverTree(TreeNode* root) {
        vector<int> inorder;
               int i=0;
        trav(root, inorder);
sort(inorder.begin(), inorder.end());
        trav2(root, inorder, i);
    }
};