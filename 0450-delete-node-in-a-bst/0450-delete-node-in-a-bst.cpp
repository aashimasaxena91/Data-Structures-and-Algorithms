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
    TreeNode* findRightMost(TreeNode* cur){
        if(!cur) return NULL;
        while(cur->right)
            cur=cur->right;
        return cur;
    }
    TreeNode* soln(TreeNode* cur,int key){
        if(!cur->right) return cur->left;
        if(!cur->left) return cur->right;
        TreeNode* curRight = cur->right;
        TreeNode* curLeftRightMost = findRightMost(cur->left);
        curLeftRightMost->right = curRight;
        return cur->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(root->val == key) return soln(root, key);
        TreeNode* cur = root;
        
        while(cur){
            if(cur->val>key){
                if(cur->left && cur->left->val == key){
                    cur->left = soln(cur->left, key);
                    break;
                }else
                    cur=cur->left;
            }else{
                if(cur->right && cur->right->val == key){
                cur->right = soln(cur->right, key);
                    break;
                }else
                    cur=cur->right;
            }
        }        
        
        return root;
    }
};