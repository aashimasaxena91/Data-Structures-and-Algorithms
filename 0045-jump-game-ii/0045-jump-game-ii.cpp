class Solution {
public:
    int jump(vector<int>& nums) {
        int lastPos=0, maxReach =0,  i=0, jumps=0, n= nums.size();
        while(lastPos<n-1){
            maxReach = max(maxReach, nums[i]+i);
            if(lastPos==i){
                lastPos= maxReach;
                jumps++;
            }
            i++;
        }
        return jumps;
    }
};