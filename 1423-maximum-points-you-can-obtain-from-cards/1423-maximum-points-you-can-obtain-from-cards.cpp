class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int tsum = 0, sum = 0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            tsum+= nums[i];
        }
         if (k == n) return tsum;
        for(int t=0;t<n-k;t++){
            sum+= nums[t];
        }
        int res = tsum - sum;
        for(int t = n-k, i=0;t<n;t++, i++){
            sum = sum - nums[i] + nums[t];
            res = max(res,tsum - sum);
        }
        return res;
    }
};