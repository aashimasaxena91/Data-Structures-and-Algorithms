class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int lsum =0;
        int tsum = 0;
        for(int i=0;i<nums.size();i++){
            tsum+=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(tsum-nums[i] == lsum ) return i;
            lsum+=nums[i];
            tsum-=nums[i];
        }
        return -1;
    }
};