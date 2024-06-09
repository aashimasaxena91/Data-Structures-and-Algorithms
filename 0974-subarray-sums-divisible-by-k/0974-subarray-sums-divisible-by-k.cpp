class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int preSum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            preSum+=nums[i];
            int r = preSum%k;
            if(r<0) r = r+k;
            if(r==0) ans++;
            if(mp.find(r)!=mp.end()){
                ans+=mp[r];
            }
            mp[r]++;
        }
        return ans;
    }
};