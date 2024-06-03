class Solution {
public:

    vector<vector<int>> ans;
    
    void permute(vector<int>& nums, int k=0){
        if(k==nums.size()){
                ans.push_back(nums);
                return;
            }
                unordered_set<int> s;

        for(int i=k;i<nums.size();i++){
            if(s.find(nums[i])!=s.end() ) continue;
             swap(nums[i], nums[k]);
              s.insert(nums[k]);
            
            permute(nums, k+1);
        swap(nums[i], nums[k]);
            
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
            permute(nums, 0);
        return ans;
    }
};