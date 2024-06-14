class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        // if(n==1) return 0;
        sort(nums.begin(), nums.end());
        int ans =0;
        
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                int temp = abs(nums[i-1] - nums[i]);
                nums[i] += temp +1 ;
                ans += temp +1;
            }
        }
        return ans;
    }
};