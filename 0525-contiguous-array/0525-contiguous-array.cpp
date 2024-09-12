class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> mp(2*nums.size()+1, INT_MIN);
        int res=0;
        int tsum=0;
        for(int i=0;i<nums.size();i++){
            tsum+= nums[i]==0 ? -1: 1;
            if(tsum ==0 ){
                res = i+1;
            } else if(mp[nums.size()-tsum]!=INT_MIN){
                res=max(res, i-mp[nums.size()-tsum]);
            }else
             mp[nums.size()-tsum] = i;
        }
        return res;
    }
};