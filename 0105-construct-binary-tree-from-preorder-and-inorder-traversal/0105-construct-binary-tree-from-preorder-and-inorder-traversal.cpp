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
    TreeNode* soln(vector<int> & preorder, int preStart, int preEnd, vector<int> & inorder, int inStart, int inEnd, unordered_map<int, int> &mp){
        if(inStart>inEnd || preStart>preEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inPos = mp[preorder[preStart]];
        int numsLeft = inPos - inStart;
        root->left = soln(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inPos-1, mp);
        root->right = soln(preorder, preStart+1+numsLeft , preEnd, inorder, inPos+1, inEnd, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]] = i;
        return soln(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);

    }
};