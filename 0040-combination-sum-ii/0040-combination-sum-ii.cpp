class Solution {
public:

    void soln(vector<int>& nums, int n, int i, vector<vector<int>>& res,vector<int>& ans, int target ){
        if(target ==0){
           res.push_back(ans);
            return;
        }
        
        if(i>=n || target<0) return;
        
        if(nums[i]>target) i++;
        if(i>=n) return;
        ans.push_back(nums[i]);
        soln(nums, n, i+1, res, ans, target -nums[i]);
        ans.pop_back();
        i++;
        while(i<n && nums[i]==nums[i-1]) i++;
        soln(nums, n, i, res, ans, target);
        
    }
  
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
          vector<vector<int>> res;
        vector<int> ans;
        soln(nums, nums.size(),0, res, ans, target);
        return res;
    }
    
};