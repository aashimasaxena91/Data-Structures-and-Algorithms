class Solution {
    
public:
    void soln(vector<int>& nums, int n, int i, vector<vector<int>> &ans, vector<int> temp, set<vector<int>> & mp){
        if(i==n){
            if(mp.find(temp)==mp.end()){
                ans.push_back(temp);
                mp.insert(temp);
            }
                
            return;
        }
        
        soln(nums, n, i+1, ans, temp, mp);
        // if(i>0 && nums[i]!=nums[i-1])
         temp.push_back(nums[i]);
       
        soln(nums, n, i+1, ans, temp, mp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> m;
        vector<int> temp;
        soln(nums, nums.size(), 0, ans, temp, m);
        return ans;
    }
};