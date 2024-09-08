class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long int ans =0;
        int m =0;
        for(auto x: nums){
            ans+= m;
            m = max(m, x);
        }
        return ans;
    }
};