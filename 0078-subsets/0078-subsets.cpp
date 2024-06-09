class Solution {
public:
    void soln(vector<int>& nums, int n, vector<vector<int>>& ans, vector<int> & temp, int i ){
        if(i>n) return;
        if(i==n){
            ans.push_back(temp);
            return;
        }
        soln(nums, n, ans, temp, i+1);
        temp.push_back(nums[i]);
        soln(nums, n, ans, temp, i+1);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> ans;
        vector<int> temp;
        soln(nums, nums.size(), ans, temp, 0);
        return ans;
    }
};