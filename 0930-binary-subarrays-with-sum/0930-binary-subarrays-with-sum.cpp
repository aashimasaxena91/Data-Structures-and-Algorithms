class Solution {
public:
    int soln(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int res=0, sum=0, j=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(j<=i && sum>goal){
                sum-=nums[j];
                j++;
            }
            res+= i-j+1;
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return soln(nums, goal)- soln(nums, goal-1);
    }
};