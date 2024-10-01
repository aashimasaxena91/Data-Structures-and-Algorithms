class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans (nums.size(),1);
        for(int i=1;i<nums.size();i++){
            ans[i] = ans[i-1]* nums[i-1];
        }
        int k =nums[nums.size()-1];
        for(int j=nums.size()-2;j>=0;j--){
            ans[j] = ans[j]* k;
            k*=nums[j];
        }
        return ans;
    }
};