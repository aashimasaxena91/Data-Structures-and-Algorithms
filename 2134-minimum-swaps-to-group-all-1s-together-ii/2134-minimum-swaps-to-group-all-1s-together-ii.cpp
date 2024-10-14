class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k=0, n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1) k++;
        }
        if(k<2 || k==n) return 0;
        int a=0;
        for(int i=0;i<k;i++){
            if(nums[i]==0) a++;
        }
        int ans = a;
        for(int i=1;i<n;i++){
            if(nums[i-1] == 0) a--;
            if( nums[(i+k-1)%n] == 0) a++;
            ans = min(ans, a);
        }
        return ans;
    }
};