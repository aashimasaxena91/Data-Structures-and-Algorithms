class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums, int k=0) {
        if(k==nums.size()-1){
            ans.push_back(nums);
            return ans;
        }
        for(int i=k;i<nums.size();i++){
            swap(nums[i], nums[k]);
            
            permute(nums, k+1);
            swap(nums[i], nums[k]);
        }
        return ans;
    }
};