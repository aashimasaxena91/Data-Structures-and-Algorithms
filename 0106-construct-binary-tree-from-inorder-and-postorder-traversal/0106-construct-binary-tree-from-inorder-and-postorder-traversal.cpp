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
    
    
    TreeNode* soln(vector<int> & inorder, int inStart, int inEnd, vector<int>&postorder, int postStart, int postEnd, unordered_map<int, int> &mp){
        if(inStart>inEnd || postStart>postEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
       int inPos = mp[postorder[postEnd]];
       int numsRight = inEnd - inPos;
        root->right = soln(inorder, inPos+1, inEnd, postorder, postEnd - numsRight, postEnd-1,mp);
        root->left = soln(inorder, inStart,inPos-1 , postorder, postStart, postEnd - numsRight-1, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]] =i;
        
        return soln(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mp);
    }
};