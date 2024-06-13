class Solution {
public:
    
    void soln(int k, int n, int i, vector<vector<int>> &res, vector<int> &ans){
        if(k==ans.size()){
            if(n==0)
                res.push_back(ans);
            return;
        } 
        if(i>n || i>9) return;
        
        ans.push_back(i);
        soln(k, n-i, i+1, res, ans);
        ans.pop_back();
        soln(k, n, i+1, res, ans);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> res;
        if(k>n) return res;
        vector<int> ans;
        soln(k, n, 1, res, ans);
        return res;
    }
};