class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long, long> mp;
        long tsum =0, res=0;
        for(int i=0;i<nums.size();i++){
            tsum+=nums[i];
            if(tsum==k){
                res = i+1;
            }
            if(mp.find(tsum)==mp.end()){
                mp[tsum] =i; 
            }
            if(mp.find(tsum-k) != mp.end()){
            res = max(i-mp[tsum-k], res);
            }
        }
        return res;
    }
};