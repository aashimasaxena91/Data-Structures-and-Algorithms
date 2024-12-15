class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans=-1;
        int l=0, r = nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if((mid==0 || nums[mid]>nums[mid-1]) && (mid ==nums.size()-1 || nums[mid]>nums[mid+1]))
             return mid;
            else if(nums[mid]<nums[mid+1]) l = mid+1;
            else r=mid-1;
        }
        return -1;
    }
};