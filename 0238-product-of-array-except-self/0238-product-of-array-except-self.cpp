class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pre=1, suf=1;
                int n=nums.size();

        vector<int> ans(n, 1);
        for(int i=0;i<n;i++){
            ans[i]*=pre;
            ans[n-1-i]*=suf;
            pre*=nums[i];
            suf*=nums[n-i-1];
        }
        return ans;
    }
};