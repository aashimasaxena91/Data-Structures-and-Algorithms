class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0) return 0;
       
        int count=0;
        int mul = 1;
        for(int l=0, r=0; r<nums.size();r++){
            mul*=nums[r];
            while(l<=r && mul>=k){
                mul/=nums[l++];
            }
            count+=r-l+1;
        }
        
        return count;
    }
};