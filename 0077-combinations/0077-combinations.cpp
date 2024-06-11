class Solution {
public:
    
    void soln(int n, int k, int i, vector<vector<int>> & ans, vector<int> temp){
        // if(l>n) return;
        // if(i>k){
        //     ans.push_back(temp);
        //     return;
        // }
        // for(int j = l;j<=n; j++){
        //     temp.push_back(j);
        //     soln(n, k, i+1, l+1, ans, temp);
        //     temp.pop_back();
        // }
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        
        for(int ind = i;ind<=n;ind++){
            temp.push_back(ind);
            soln(n, k, ind+1, ans, temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        soln(n,k,1, ans, temp);
        return ans;
    }
};