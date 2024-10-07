class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int l=0, r=0, jumps =0, farthest = 0;
        while(r<nums.size()){
            for(int j= l;j<=r;j++){
                farthest= max(farthest, nums[j]+j);
                if(farthest>=nums.size()-1) return jumps+1;
            }
            l= r+1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};