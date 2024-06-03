class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1) return ;
        int k= nums.size()-2;
        while(k>=0 && nums[k]>=nums[k+1]){
            k--;
        }
        if(k<0){
            reverse(nums.begin(), nums.end());
            return;
        }
        int l=nums.size()-1;
        while(nums[l]<=nums[k] && l>k ){
            l--;
        }
        swap(nums[l], nums[k]);
        reverse(nums.begin()+k+1, nums.end());
    }
};