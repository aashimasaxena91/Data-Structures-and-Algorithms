class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        unordered_map<int, int> mp;
        int presum=0, res=0;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            if(presum == goal) res++;
            if(mp.find(presum - goal)!=mp.end())
                res+=mp[presum-goal];
            mp[presum]++;
        }
        return res;
    }
};