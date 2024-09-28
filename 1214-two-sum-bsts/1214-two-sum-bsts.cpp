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
    void inorder(TreeNode* root, vector<int> &a){
        if(!root) return;
        inorder(root->left, a);
        a.push_back(root->val);
        inorder(root->right,a);
        
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> s;
        vector<int> a, b;
        inorder(root1,a);
        inorder(root2, b);
        for(auto j: a)
            s.insert(j);
        for(auto m:b){
            if(s.find(target- m)!=s.end())
                return true;
        }
        return false;
    }
};