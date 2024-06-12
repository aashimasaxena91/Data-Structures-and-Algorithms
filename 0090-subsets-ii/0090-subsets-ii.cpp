class Solution {
public:
    
    
    void soln(vector<int>& nums, int n, vector<vector<int>> & res, vector<int>& temp, int i){
        if(i>=n){
            res.push_back(temp);
            return;
        }
        
        temp.push_back(nums[i]);
        soln(nums,n, res, temp, i+1);
        temp.pop_back();
        i++;
        while(i<n && nums[i]==nums[i-1]) i++;
        soln(nums,n, res, temp, i);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        vector<vector<int>> res ;
        vector<int> temp;
        soln(nums, nums.size(), res, temp, 0);
       
        return res;
    }
};