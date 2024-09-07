class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size()<4) return nums;
        unordered_map<int, int> mp;
        for(auto k: nums){
            mp[k]++;
        }
        vector<int> m;
        for(auto it: mp){
            if(it.second == 1)
                m.push_back(it.first);
            
        }
        return m;
    }
};