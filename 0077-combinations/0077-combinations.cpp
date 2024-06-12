class Solution {
public:
    
    void soln(int n, int k, int i, vector<vector<int>> &res, vector<int> temp ){
        if(k==0){
            res.push_back(temp);
            return;
        }
        if(i>n) return ;
        
        if(k> n-i+1) return;
        
        temp.push_back(i);
        soln(n, k-1, i+1, res, temp );
        temp.pop_back();
        soln(n,k, i+1, res, temp);
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>  res;
        vector<int> ans;
        soln(n, k, 1, res, ans);
        return res;
    }
};