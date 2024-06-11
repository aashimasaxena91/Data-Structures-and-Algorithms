class Solution {
public:
    
    void soln(vector<int>& nums, int n, int i, vector<vector<int>> &ans ){
         // if(i<n && nums[i] == nums[i+1]) i++;
        if(i>=n){
            ans.push_back(nums);
            return;
        }
        unordered_set<int>s;
        for(int k=i;k<n;k++){
            if(s.find(nums[k])!=s.end()){ continue;}
               s.insert(nums[k]);
                swap(nums[k], nums[i]);
             
                soln(nums, n, i+1, ans);
                swap(nums[k], nums[i]);
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        soln(nums, nums.size(),0, ans);
        return ans;
    }
};