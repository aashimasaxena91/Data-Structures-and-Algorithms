class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res=0;
        int tsum=0;
        for(int i=0;i<nums.size();i++){
            tsum+= nums[i]==0 ? 1: -1;
            if(tsum ==0 ){
                res = i+1;
            } else if(mp.find(tsum)!=mp.end()){
                res=max(res, i-mp[tsum]);
            }else
             mp[tsum] = i;
        }
        return res;
    }
};