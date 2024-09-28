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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> s;
        TreeNode* head = new TreeNode(preorder[0]);
        if(preorder.size()==1) return head;
        TreeNode* root = head;
        int i=1;
       while(i<preorder.size()){
            if(preorder[i]<root->val){
                s.push(root);
                root->left = new TreeNode(preorder[i]);
                root=root->left;
            }else{
                
                while(!s.empty() && s.top()->val<preorder[i]){
                     root = s.top();
                    s.pop();
                }
                root->right = new TreeNode(preorder[i]);
                root =root->right;
            }
           i++;
        }
        return head;
    }
};