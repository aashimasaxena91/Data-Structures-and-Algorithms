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
class BSTIterator {
public:
    stack<TreeNode*> s;
    
    TreeNode* l= NULL;
    BSTIterator(TreeNode* root) {
        l =root;
         while(l){
             s.push(l);
            l=l->left;
         }
    }
    
    int next() {
        l = s.top();
        s.pop();
        int k = l->val;
        l = l->right;
        while(l){
            s.push(l);
            l=l->left;
        }
        return k;
      
    }
    
    bool hasNext() {
        return !(s.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */