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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        int k=root->val;
        int s=0;
        if(k>high) return rangeSumBST(root->left, low, high);
        if(k<low) return rangeSumBST(root->right, low, high);
        if(k<=high && k>=low){ 
            s+=k;
        }
        if(k<=high){
            s+=rangeSumBST(root->left, low, high);
        }
        if(k>=low){
            s+=rangeSumBST(root->right, low, high);
        }
        return s;
    }
};