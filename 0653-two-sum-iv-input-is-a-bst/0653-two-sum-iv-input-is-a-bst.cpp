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
    int nxt(stack<TreeNode*>& s){
          if(s.empty()) return INT_MAX;
        TreeNode* t = s.top();
        s.pop();
        int k = t->val;
        t=t->right;
        while(t){
            s.push(t);
            t=t->left;
        }
        return k;
    }
    int bef(stack<TreeNode*>& s){
        if(s.empty()) return INT_MAX;
        TreeNode* t = s.top();
        s.pop();
        int k = t->val;
        t=t->left;
        while(t){
            s.push(t);
            t=t->right;
        }
        return k;
    }
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> le,re;
        TreeNode* cur= root;
        while(cur){
            le.push(cur);
            cur=cur->left;
        }
        cur = root;
        while(cur){
            re.push(cur);
            cur=cur->right;
        }
        int l = nxt(le);
        int r = bef(re);
        while(l!=INT_MAX && r!=INT_MAX && l<r){
            if(l+r == k){
                return true;
            }else if(l+r<k){
                l = nxt(le);
            }else
                r = bef(re);
        }
        return false;
    }
};