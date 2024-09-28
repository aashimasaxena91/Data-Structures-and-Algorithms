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
    
    bool findPath(TreeNode* root, TreeNode* p, vector<TreeNode*> & d){
        if(root ==NULL) return false;
        d.push_back(root);
        if(root->val == p->val) return true;
        if(findPath(root->left, p, d) || findPath(root->right, p, d)) return true;
        d.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a, b;
       findPath(root, p, a);
        findPath(root, q, b);
TreeNode* k = NULL;
        for(int i=0;i<a.size() && i<b.size();i++){
          
            if(a[i]->val!=b[i]->val){
                break;
            }
              k = a[i];
        }
        return k;
    }
};