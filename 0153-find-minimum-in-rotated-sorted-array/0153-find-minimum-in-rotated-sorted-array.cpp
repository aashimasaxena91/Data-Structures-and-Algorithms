class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size(), ans=INT_MAX;
        int l=0, r= n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            ans = min(nums[mid], ans);
            if(nums[mid]>nums[r]){
                l=mid+1;
            }else
                r=mid-1;
        }
        return ans;
    }
};