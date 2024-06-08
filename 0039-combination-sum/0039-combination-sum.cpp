class Solution {
public:
    
    void soln(vector<int>& candidates, int target, int i, vector<vector<int>> & ans, int sum, vector<int>& temp){
        
        if(i>=candidates.size() ){
            if(sum == target ){
            ans.push_back(temp);
     
           }
            return;
        }
        if(sum>target) return ;
       
        
       if(candidates[i]<=target-sum){
            temp.push_back(candidates[i]);
            sum+=candidates[i];
           soln(candidates, target, i, ans, sum, temp);
            temp.pop_back();
            sum-=candidates[i];
           
        }
        soln(candidates, target, i+1, ans, sum, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        soln(candidates, target, 0, ans, 0, temp);
        return ans;
    }
};