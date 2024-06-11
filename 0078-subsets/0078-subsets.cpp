class Solution {
public:
    
    void ans(vector<int>& nums, int n, int i,vector<vector<int>> & soln, vector<int> temp){
        if(i==n){
            soln.push_back(temp);
            return;
        }
        ans(nums, n, i+1, soln, temp);
        temp.push_back(nums[i]);
        ans(nums, n, i+1, soln, temp);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>soln;
        vector<int> temp;
        ans(nums, nums.size(),0,soln, temp );
        return soln;
    }
};