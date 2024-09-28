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
    bool isValidBST(TreeNode* root) {
        vector<int> k;
        while(root){
            if(root->left==NULL){
                k.push_back(root->val);
                root=root->right;
            }else{
                TreeNode* r = root->left;
                while(r->right && r->right!=root)
                    r=r->right;
                if(r->right==NULL){
                    r->right = root;
                    root=root->left;
                }else{
                    r->right =NULL;
                    k.push_back(root->val);
                    root=root->right;
                }
            }
        }
        for(int i=1;i<k.size();i++){
            if(k[i-1]>=k[i]) return false;
        }
        return true;
    }
};