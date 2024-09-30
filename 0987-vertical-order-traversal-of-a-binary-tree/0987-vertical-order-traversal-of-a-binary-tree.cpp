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
    void dfs(TreeNode* root, int vh, int l,  map<int,map<int, priority_queue<int, vector<int>, greater<int> > >> &mp){
        if(!root) return;
        dfs(root->left, vh-1, l+1, mp);
        mp[vh][l].push(root->val);
        dfs(root->right, vh+1, l+1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, priority_queue<int, vector<int>, greater<int>>>> mp;
       
        dfs(root, 0, 0, mp);
        for(auto k: mp){
            vector<int> a;
            for(auto t: k.second){
                while(!t.second.empty()){
                int l = t.second.top();
                t.second.pop();
                a.push_back(l);
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};