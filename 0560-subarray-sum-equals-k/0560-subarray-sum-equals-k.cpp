class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count=0;
        int preSum =0;
        for(int i=0;i<nums.size();i++){
            preSum+=nums[i];
            if(preSum==k) count++;
            
            if(mp.find(preSum - k)!=mp.end()){
                count+=mp[preSum - k];
            }
            mp[preSum]++;
        }
        return count;
    }
};