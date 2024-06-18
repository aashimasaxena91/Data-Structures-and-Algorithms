class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int minStep=0;
        for(int i=n-1;i>0;i--){
           nums[i] +=minStep;
           int temp = nums[i]- nums[0];
            nums[0] = nums[i];
            minStep+=temp;

        }
        return minStep;
    }
};