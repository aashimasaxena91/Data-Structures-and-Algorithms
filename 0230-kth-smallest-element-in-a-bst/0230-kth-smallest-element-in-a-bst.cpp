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
   void inorder_traversal(TreeNode* root, int k, vector<int> &q){
        if(root ==NULL) return;
       if(q.size()>=k) return;
        inorder_traversal(root->left, k,q);
        q.push_back(root->val);
        
        inorder_traversal(root->right, k,q);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> q;
        inorder_traversal(root, k, q);
        return q[k-1];
    }
};