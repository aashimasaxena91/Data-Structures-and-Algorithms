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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int s = q.size();
            int l =1;
            for(int i=1;i<=s;i++){
                auto m = q.front();
                q.pop();
                if(i==s){
                    ans.push_back(m->val);
                }
                if(m->left)
                    q.push(m->left);
                if(m->right)
                    q.push(m->right);
            }
        }
        return ans;
    }
};